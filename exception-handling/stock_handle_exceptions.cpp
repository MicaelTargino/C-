#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <stdexcept>

using std::string;
using std::shared_ptr;
using std::make_shared;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::exception;

class product_not_found: public exception {
public:
    const char* what() const noexcept {
        return "Product not found";
    }
};

class quantity_insufficient: public exception {
public:
    const char* what() const noexcept {
        return "Quantity insufficient";
    }
};

class invalid_quantity: public exception {
public:
    const char* what() const noexcept {
        return "Invalid quantity";
    }
};

class product {
    int id;
    string name; 
    int quantity;
    double price;
public:
    product(int i, string n, int q, double p): id(i), name(n), quantity(q), price(p) {}

    int get_id() { return id; }
    void set_id(int i) { id = i; }

    string get_name() { return name; }
    void set_name(const string& na) { name = na; }

    int get_quantity() { return quantity; }
    void set_quantity(int q) { quantity = q; }

    double get_price() { return price; }
    void set_price(double p) { price = p; }
};

class stock {
    vector<product> products;
public:
    void add_product(product p) { 
        products.push_back(p); 
        cout << "[stock] Product: " << p.get_name();
        cout << " added to stock" << endl;
    }

    void remove_product(int product_id) { 
        for(auto it = products.begin(); it != products.end(); ++it) {
            if(it->get_id() == product_id) {
                cout << "[stock] product: " << it->get_name() << " removed" << endl;
                products.erase(it);
                return;
            } 
        } 
        throw product_not_found();
    }

    void update_quantity(int product_id, int q) {
        if (q < 0) {
            throw invalid_quantity();
        }
        for (auto p : products) {
            if(p.get_id() == product_id) {
                if(q > p.get_quantity()) { 
                    throw quantity_insufficient();
                }
                p.set_quantity(p.get_quantity() - q);
                cout << "[stock] product" << p.get_name() << "with stock updated to: ";
                cout << p.get_quantity() << endl;
            }
        }
    }

    void check_product(int product_id) {
        for(auto p: products) {
            if(p.get_id() == product_id) {
                cout << "[stock] product " << p.get_name();
                cout << "(" << p.get_id() << "): "<< endl;
                cout << "Price: " << p.get_price() << endl; 
                cout << "Quantity: " << p.get_quantity() << endl;
                cout << "--------------------" << endl;
                return;
            }
        }
        throw product_not_found();
    }

    friend std::ostream& operator<<(std::ostream& os,  stock& e) {
          os << "[stock] general stock: " << endl;
          for(auto p: e.products) {
            os << "[stock] product " << p.get_name();
            os << "(" << p.get_id() << "): "<< endl;
            os << "Price: " << p.get_price() << endl; 
            os << "Quantity: " << p.get_quantity() << endl;
            os << "--------------------" << endl;
        }     
        return os; 
    }
};

int main(void) {
    stock general_stock;

    try {  
        general_stock.add_product(product(1, "Pen", 100, 3.50));
        general_stock.add_product(product(2, "Notebook", 50, 15.40));
        general_stock.add_product(product(3, "Eraser", 80, 2.20));
        general_stock.add_product(product(4, "Pencil", 120, 3.00));

        cout << general_stock << endl;

        general_stock.update_quantity(1, -20); // invalid quantity: negative
        general_stock.update_quantity(3, 100); // quantity insufficient: too big
        general_stock.remove_product(10); // product not found


    } catch (const product_not_found& e) {
        std::cerr << e.what() << endl;
    } catch (const quantity_insufficient& e) {
        std::cerr << e.what() << endl;
    } catch (const invalid_quantity& e) {
        std::cerr << e.what() << endl;
    }

    return 0;
}