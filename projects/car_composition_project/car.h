#ifndef car_H
#define car_H

#include <string>
#include <memory>
#include "engine.h"
#include "wheel.h"
#include "chassis.h"

using std::string;

class car {
    string license_plate;
    std::unique_ptr<engine> car_engine;
    std::unique_ptr<chassis> car_chassis;
    std::unique_ptr<wheel> car_wheel;
public:
    car(const string& p, std::unique_ptr<engine> engine,
        std::unique_ptr<wheel> wheel,
        std::unique_ptr<chassis> chassis);
    ~car();
    void start();
    void set_engine(std::unique_ptr<engine> new_engine);
    std::unique_ptr<engine> remove_engine();
};

#endif //car_H
