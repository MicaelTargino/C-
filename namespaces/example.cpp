#include <iostream>

namespace math {
    int sum(int a, int b) {
        return a+b;
    }
    int sub(int a, int b) {
        return a-b;
    }
}  

using math::sub;

int main() {
    int x,y,a,b;
    a=10;
    b=20;

    x = math::sum(a,b);
    y = sub(a,b);

    std::cout << x << std::endl;
}