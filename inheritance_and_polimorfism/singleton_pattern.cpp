#include <iostream>
#include <random>

using std::cout;
using std::endl;

class singleton {
	int var;
	static singleton* instance;

	singleton() {
		std::random_device dev;
		std::mt19937 rng(dev());
		std::uniform_int_distribution<std::mt19937::result_type> dist6(1,10);
		var = dist6(rng);
		cout << "instancia criada!" << endl;
	}

	~singleton() {
		cout << "instancia finalizada!" << endl;
	}
public:
	static singleton* get_instance() {
		if (!instance) {
			instance = new singleton();
		}
		return instance;
	}

	void print_info() {
		cout << "singleton(" << var << ")" << endl;
	}

	static void destroy_instance() {
		delete instance;
		instance = nullptr;
	}
};

singleton* singleton::instance = nullptr;

int main(void) {
	singleton* s1 = singleton::get_instance();
	singleton* s2 = singleton::get_instance();

	s1->print_info();
	s2->print_info();

	if (s1 == s2) {
		cout << "s1 e s2 apontam para a mesma instancia" << endl;
	}

	singleton::destroy_instance();

	s1 = singleton::get_instance();
	s2 = singleton::get_instance();

	s1->print_info();
        s2->print_info();

        if (s1 == s2) {
                cout << "s1 e s2 apontam para a mesma instancia" << endl;
        }



}
