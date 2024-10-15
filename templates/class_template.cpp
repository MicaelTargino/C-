#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::ostream;
using std::string;

class complex_number {
    double real;
    double img;
public:
    complex_number(double r, double i): real(r), img(i) {}
    bool operator>(const complex_number& other) {
        return (real + img) > (other.real + other.img);
    }

    friend ostream& operator<<(ostream& out,  const complex_number& cn) {
        out << "(" << cn.real << "," << cn.img << "i)";
        return out;
    }

    complex_number operator+(const complex_number& cn) {
        return complex_number(real + cn.real, img + cn.img); 
    }
};

template <typename T>
class thing {
    T attr;
public:
    thing(T atr) : attr(atr) {}
    T get_attr() {
        return attr;
    }
    void set_attr(T value) {
        attr = value;
    }
};

int main(void) {
    thing<int> t1(15);
    thing<double> t2(3.2);
    thing<complex_number> t3(complex_number(0.5, 1.8));
    thing<string> t4("Hello, World!");

    cout << t1.get_attr() << endl; // will print an int
    cout << t2.get_attr() << endl; // will print a double
    cout << t3.get_attr() << endl; // will print a complex number
    cout << t4.get_attr() << endl; // will print a string
}