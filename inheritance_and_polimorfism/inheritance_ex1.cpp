#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class animal {
	int idade;
protected:
	int var;
public:
	animal(int i = 0):idade(i) {
		cout << "animal(" << idade << ")" << endl;
	}
	~animal() {
		cout << "~animal(" << idade << ")" << endl;
	}
	int get_idade() { return idade; }
	void set_idade(int i) { idade = i; }
	void print_info() {
		cout << "animal(" << idade << ")" << endl;
	}
};

class cachorro : public animal {
	string latido;
public:
	cachorro(int i, const string& l):animal(i), latido(l) {
		cout << "cachorro(" << get_idade();
		cout << ", " << latido << ")" << endl;
		var = 1000;
	}
	~cachorro() {
		cout << "~cachorro(" << get_idade();
		cout << ", " << latido << ")" << endl;
	}
	string& get_latido() { return latido; }
	void set_latido(const string& l) { latido = l; }
	void print_info() {
		cout << "cachorro(" << get_idade() << ", ";
		cout << latido << "," << var <<")" << endl;
	}
};

int main(void) {
	cachorro c1(7, "AUAU");
	cachorro c2(9, "AWAW");

	cout << endl;

	c1.print_info();
	c2.print_info();


	cout << endl;

//	animal* pa = &c1;

//	pa->set_idade(10);

//	pa->print_info();

	return 0;
}



