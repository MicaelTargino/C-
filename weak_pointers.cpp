#include <iostream>
#include <memory>

using namespace std;

class coisa {
  int att;
public:
  coisa(int a) : att(a) {}
  void fazer_algo() {
    cout << "fazer_algo(" << att << ")" << std::endl;
  }
  
};

int main() {
  shared_ptr<coisa> ptr1 = make_shared<coisa>(999);
  weak_ptr<coisa> wptr = ptr1;

  cout << "ptr1.use_count() = " << ptr1.use_count() << endl;

  ptr1->fazer_algo();
  if (auto shared_ptr = wptr.lock()) {
    shared_ptr->fazer_algo();
  } else {
    cout << "wptr.lock() returned nullptr" << endl;
  }

  
  
  return 0;
}