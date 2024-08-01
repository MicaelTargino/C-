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
  shared_ptr<coisa> ptr1 = make_shared<coisa>(998);

  {
    shared_ptr<coisa> ptr2 = ptr1;
    cout << "Contagem de refs: " << ptr1.use_count() << endl;
  }

   cout << "Contagem de refs (pos escopo): " << ptr1.use_count() << endl;

  return 0;
}