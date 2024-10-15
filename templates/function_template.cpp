#include <iostream>

using std::cout;
using std::endl;
using std::ostream;

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
T max_value(T a, T b) {
    return (a>b) ? a : b;
}

template <typename T>
T sum(T a, T b) {
    return a + b;
}

int main(void) {
    complex_number cn1(0.5, 1.2);
    complex_number cn2(2.3, 0.2);

    cout << max_value(cn1, cn2) << endl;
    cout << max_value(4.21,6.2) << endl;
    cout << max_value('a', 'z') << endl;

    cout << sum(cn1, cn2) << endl;
    cout << sum(4.21, 6.2) << endl;
}