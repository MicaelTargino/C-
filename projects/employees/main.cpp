#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::vector;

class employee {
    int id;
    string name;
    double base_salary;
    static int total_employees;
public:
    // constructors and destructors will control the total_employees static variable.
    employee(int id, string name, double base_salary): id(id), name(name), base_salary(base_salary) {
        total_employees++;
    };
    ~employee() {
        total_employees--;
    };

    // getters and setters
    int get_id() { return id; };
    void set_id(int i) { id = i; };

    string get_name() { return name; };
    void set_name(const string& n) { name = n; };

    double get_base_salary() { return base_salary; };
    void set_base_salary(double bs) { base_salary = bs; };

    // static method to get the count of employees.
    static int get_total_employees() {
        return total_employees;
    };

    // virtual methods that are going to be implemented in child classes.
    virtual string get_role() = 0;    
    virtual double calculate_salary() = 0;

    void show_info() {
        cout << "---- Employee " << get_role() << " ---- " << endl;
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Base Salary: " << base_salary << endl;
        cout << "Full Salary: " << calculate_salary() << endl;
        cout << "-------------------" << endl;
    };
};

class manager: virtual public employee {
    int team_size;
public:
    manager(int id, string name, double base_salary, int team_size): employee(id, name, base_salary), team_size(team_size) {};

    int get_team_size() { return team_size; };
    void set_team_size(int ts) { team_size = ts; };

    string get_role() { return "manager"; };
    double calculate_salary() { return get_base_salary() * (team_size/2); };

};

class developer: virtual public employee {
    string programming_language;
public: 
    developer(int id, string name, double base_salary, const string& programming_language): employee(id, name, base_salary), programming_language(programming_language) {};

    string get_programming_language() { return programming_language; };
    void set_programming_language(const string& pl) { programming_language = pl; };

    string get_role() { return "developer"; };
    double calculate_salary() { return get_base_salary() * 2 ;};
};

class tech_lead: public manager, public developer {
public: 
    tech_lead(int id, string name, double base_salary, int team_size, const string& programming_language):
                employee(id, name, base_salary),
                manager(id, name, base_salary, team_size),
                developer(id, name, base_salary, programming_language) {};

    string get_role() { return "tech lead"; };
    double calculate_salary() { return get_base_salary() * get_team_size(); };
};

int employee::total_employees = 0;

int main() {
    // Creating employees
    manager g1(0, "Manuel", 3000, 7);
    tech_lead tl1(1, "Thomas", 3500, 3, "Python");
    tech_lead tl2(2, "Silvio", 3500, 2, "Assembly");
    developer d1(3, "Caio", 2000, "JavaScript");
    developer d2(4, "Henrique", 2500, "C++");
    developer d3(5, "Heitor", 2600, "COBOL");
    developer d4(6, "Hefesto", 2700, "Elixir");
    developer d5(7, "Natanael", 2800, "Go");

    // Store all employees in a vector
    vector<employee*> employees = {&g1, &tl1, &tl2, &d1, &d2, &d3, &d4, &d5};

    // Showing employee information
    for (auto emp : employees) {
        emp->show_info();
    }

    // Showing total number of employees
    cout << "Total number of employees: " << employee::get_total_employees() << endl;

    cout << "List of programming languages: ";
    cout << "(";
    for(int i = 0; i < employees.size(); i++) {
        auto emp = employees[i];
        // Checking if employee is a developer or tech lead
        developer* dev = dynamic_cast<developer*>(emp);
        if (dev != nullptr) {
            cout << dev->get_programming_language();

            // dont print the comma if the employee is the last one
            if (i < employees.size() - 1) {
                cout << ", ";
            }
        }
    }
    cout << ")" << endl;

    return 0;
}