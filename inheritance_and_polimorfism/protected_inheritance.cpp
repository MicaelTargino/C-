#include <iostream>

using std::cout;
using std::endl;

class base {
	int priv_valor;
protected:
	int prot_valor;
public:
	int get_priv_valor() {
		return priv_valor;
	}
	void set_priv_valor(int i) {
		priv_valor = i;
	}

	void set_prot_valor(int i) {
		prot_valor = i;
	}
	int get_prot_valor() {
		return prot_valor;
	}
};

class derivada : public base {
public:
	int pub_valor;

	void set_prot_valor(int i) { //sobrescreve
		prot_valor = (2*i);
	}

};

int main(void) {
	base b1;
	derivada d1;

	b1.set_prot_valor(10);

	d1.set_prot_valor(10);

	cout << "b1.prot_valor = " << b1.get_prot_valor();
	cout << endl;
	cout << "d1.prot_valor = " << d1.get_prot_valor();

	return 0;
}
