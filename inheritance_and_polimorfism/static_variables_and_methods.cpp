#include <iostream>

using std::cout;
using std::endl;

class ponto {
	double x;
	double y;
	static int contador;
public:
	ponto(double xx, double yy):x(xx), y(yy) { 
		contador++;
		cout << "ponto()" << endl;
	}

	~ponto() {
		contador--;
		cout << "~ponto()" << endl;
	}

	static int get_contador() {
		return contador;
	}

	void print_info() {
		cout << "ponto(" << x << ", " << y << ")" << endl;
	}
};

int ponto::contador = 0;

int main(void) {

	cout << "Existem: " << ponto::get_contador() << " pontos" << endl;

	ponto p1(0.5, 1.3);
	p1.print_info();

	ponto p2(3.4, 6.5);
	p2.print_info();

	ponto* pp3 = new ponto(1.2, 3.5);
	pp3->print_info();

	cout << "Existem: " << ponto::get_contador() << " pontos" << endl;

	delete pp3;

	cout << "Existem: " << ponto::get_contador() << " pontos" << endl;

}
