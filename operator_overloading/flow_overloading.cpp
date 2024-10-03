#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;

class rectangle {
    double width;
    double height;
public:
    rectangle(double w, double h) : width(w), height(h) {}

    double area() const { return width * height; }

    void print_info() const {
        cout << "rectangle(" << width << ", " << height << ")" << endl;
    }

    friend ostream& operator<<(ostream& out, const rectangle& r) {
        out << "retangulo(" << r.width << ", " << r.height << ")" << endl;
        return out;
    }

    friend istream& operator>>(istream& in, rectangle& r) {
        in >> r.width >> r.height;
        return in;
    }
};

int main(void) {
    rectangle r1(4,4);
    rectangle r7(0,0);

    cout << r1;

    cin >> r7;

    cout << r7;
}