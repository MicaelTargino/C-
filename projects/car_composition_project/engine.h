#ifndef engine_H
#define engine_H

#include <string>

using std::string;

class engine {
    string model;
    double displacement;
public:
    engine(const string& model, double displacement);
    ~engine();

    void start();

};

#endif //engine_H
