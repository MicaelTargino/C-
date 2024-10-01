#include <iostream>

using std::cout;
using std::endl;

class rectangle {
    double width;
    double height;
public:
    rectangle(double w, double h) : width(w), height(h) {}

    void print_info() const {
        cout << "rectangle(" << width << ", " << height << ")" << endl;
    }

    // operator overloading using member function
    rectangle operator+(const rectangle& other) {
        return rectangle(width + other.width, height + other.height);
    }

    // operator overloading using friend function
    friend rectangle operator-(const rectangle& same, const rectangle& other) {
        return rectangle(same.width - other.width, same.height - other.height);
    }
};

int main(void) {
    rectangle r1(2,2);
    rectangle r2(3,3);

    rectangle r3 = r1 + r2;
    rectangle r4 = r2 - r1;

    r1.print_info();
    r2.print_info();
    r3.print_info();
    r4.print_info();
}