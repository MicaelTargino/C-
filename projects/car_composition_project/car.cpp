#include "car.h"
#include <iostream>

using std::cout;
using std::endl;

car::car(const std::string& license_plate, std::unique_ptr<engine> engine,
         std::unique_ptr<wheel> wheel,
         std::unique_ptr<chassis> chassis): license_plate(license_plate),
                                            car_engine(std::move(engine)),
                                            car_wheel(std::move(wheel)),
                                            car_chassis(std::move(chassis)) {
    cout << "car(" << license_plate << ") " << endl;
}

car::~car() {
    cout << "~car(" << license_plate << ") " << endl;
}

void car::start() {
    cout << "car::start()" << endl;
    if (car_engine) car_engine->start();
    if (car_wheel) car_wheel->spin();
    if (car_chassis) car_chassis->support();
    cout << "vroom vroom - car started!" << endl;
}

void car::set_engine(std::unique_ptr<engine> new_engine) {
    car_engine = std::move(new_engine);
}

std::unique_ptr<engine> car::remove_engine() {
    return std::move(car_engine);
}
