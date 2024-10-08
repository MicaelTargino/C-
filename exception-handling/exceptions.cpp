#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main(void) {
    int x;

    cout << "Digite um numero: ";
    cin >> x;

    try {
        if (x % 2 == 0) {
            if (x > 10) {
                throw ((double)(0.5 * x) + 0.1);
            }
            throw x;
        } else {
            cout << "Tudo ok" << endl;
        }
    } catch (int e) {
        cout << "Int Exception: " << e << endl;
    } catch (double e) {
        cout << "Double Exception: " << e << endl;
    }


    return 0;
}
