#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

class ioexception {
public:
    virtual string message()=0;
};

class input_exception: public ioexception {
public:
    string message() {
        return "INPUT ERROR";
    }    
};

class output_exception: public ioexception {
public:
    string message() {
        return "OUTPUT ERROR";
    }
};

int main(void) {
    int num;

    cout << "Digite um numero: " << endl;
    cin >> num;
    try {
        if (num == 10) {
            throw new input_exception();
        } else if (num == 20) {
            throw new output_exception();
        } 

        cout << "tudo ok" << endl;

    } catch (ioexception* e) {
        cout << e->message() << endl;
    }

    return 0;
}

