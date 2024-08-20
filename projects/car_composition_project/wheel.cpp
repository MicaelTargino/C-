#include "wheel.h"
#include <iostream>

using std::cout;
using std::endl;

wheel::wheel(int rim) : rim(rim) {
    cout << "wheel(" << rim << ") " << endl;
}

wheel::~wheel() {
    cout << "~wheel()" << endl;
}

void wheel::spin() {
    cout << "wheel(" << rim << ").spin()" << endl;
}
