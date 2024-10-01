#include <iostream>

using std::cout;
using std::endl;

class rectangle {
    double width;
    double height;
public:
    rectangle(double w, double h) : width(w), height(h) {}

    double area() const { return width * height; }

    void print_info() const {
        cout << "rectangle(" << width << ", " << height << ")" << endl;
    }

    bool operator==(const rectangle& other) const {
        return width == other.width && height == other.height;
    }

    bool operator>(const rectangle& other) const {
        return area() > other.area();
    }

    bool operator<(const rectangle& other) const {
        return area() < other.area();
    }

};

int main(void) {
    rectangle r1(4,4);
    rectangle r2(4,4);
    rectangle r3(5,5);

    cout << (r1 == r2) << endl; // should print 1
    cout << (r1 == r3) << endl; // should print 0
    cout << (r2 > r3) << endl; // should print 0
    cout << (r2 < r3) << endl; // should print 1
}