#include <iostream>
#include "car.h"

using std::cout;
using std::cin;
using std::endl;

int main() {

    cout << "Creating car1: " << endl;
    car car1("AA123",
             std::make_unique<engine>("V8", 2.0),
             std::make_unique<wheel>(15),
             std::make_unique<chassis>("Steel", "234A"));

    car1.start();

    cout << "Creating car2: " << endl;

    car car2("AB987",
             std::make_unique<engine>("V12", 3.0),
             std::make_unique<wheel>(14),
             std::make_unique<chassis>("Steel", "754B"));

    car2.start();

    cout << "Swap engines and start both cars" << endl;

    auto removed_engine_1 = car1.remove_engine();
    auto removed_engine_2 = car2.remove_engine();

    car1.set_engine(std::move(removed_engine_2));
    car2.set_engine(std::move(removed_engine_1));

    cout << "Starting car1 and car2" << endl;
    car1.start();
    car2.start();

    return 0;
}
