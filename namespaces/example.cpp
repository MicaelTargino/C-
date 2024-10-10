#include <iostream>

namespace math {
    int sum(int a, int b) {
        return a+b;
    }
}  

int main() {
    int x,a,b;
    a=10;
    b=20;

    x = math::sum(a,b);

    std::cout << x << std::endl;
}