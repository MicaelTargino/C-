#include "engine.h"
#include <iostream>

using std::cout;
using std::endl;

engine::engine(const std::string& model, double displacement)
    : model(model), displacement(displacement) {
    cout << "engine(" << model << ")" << endl;
}

engine::~engine() {
    cout << "~engine(" << model << ")" << endl;
}

void engine::start() {
    cout << "engine.start(" << model << ", ";
    cout << displacement << ") " << endl;
}
