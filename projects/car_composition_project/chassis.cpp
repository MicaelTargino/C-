#include "chassis.h"
#include <iostream>

using std::cout;
using std::endl;

chassis::chassis(const std::string& material, const std::string& serial)
    : material(material), serial(serial) {
    cout << "chassis(" << material << ", ";
    cout << serial << ")" << endl;
}

chassis::~chassis() {
    cout << "~chassis(" << serial << ")" << endl;
}

void chassis::support() {
    cout << "chassis(" << serial << ").support()";
    cout << endl;
}
