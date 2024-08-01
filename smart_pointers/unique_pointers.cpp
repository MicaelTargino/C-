#include <iostream>
#include <memory>
using namespace std;

class coisa {
    int att;
public:
  coisa(int i):att(i) {}
  void fazer_algo() {
    cout << "coisa::fazer_algo("<< att << ")" << endl;
  }
};

int main() {
  unique_ptr<coisa> ptr = make_unique<coisa>(999);

  ptr->fazer_algo();

   // unique_ptr<coisa> ptr2 = ptr; // WRONG! The pointer is unique;
  unique_ptr<coisa> ptr2 = move(ptr); // CORRECT! The unique pointer was moved;
  
  ptr2->fazer_algo();
  return 0;
}
