#ifndef chassis_H
#define chassis_H

#include <string>

using std::string;

class chassis {
    string material;
    string serial;
public:
    chassis(const string& material, const string& serial);
    ~chassis();

    void support();
};

#endif //chassis_H
