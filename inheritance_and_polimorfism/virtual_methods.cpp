#include <iostream>
#include <string>

#define PI 3.1415

using std::cout;
using std::endl;
using std::string;

class poligono {
protected:
	string cor;
public:
	string get_cor() {
		return cor;
	}

	void set_cor(const string& c) {
		cor = c;
	}

	virtual double get_area() const {
		return 0;
	}
};

class circulo : public poligono {
	double raio;
public:
	circulo(const string& c, double r):raio(r) {
		cor = c;
	}

	double get_raio() const { return raio; }

	void set_raio(double r) { raio = r; }

	double get_area() const {
		return PI*(raio*raio);
	}
};

class retangulo : public poligono {
	double base;
	double altura;
public:
	retangulo(const string& c, double b, double a):
				base(b), altura(a) {
		cor = c;
	}
	double get_base() const {
		return base;
	}

	void set_base(double b) {
		base = b;
	}

	double get_altura() {
		return altura;
	}

	void set_altura(double a) {
		altura = a;
	}

	double get_area() const {
		return base*altura;
	}
};

class triangulo : public poligono {
	double base;
	double altura;
public:
	triangulo(const string& c, double b, double a):
				base(b),altura(a) {
		cor = c;
	}


	double get_base() {
		return base;
	}

	void set_base(double b) {
		base = b;
	}

	double get_altura() {
		return altura;
	}

	void set_altura(double a) {
		altura = a;
	}

	double get_area() const {
		return (base*altura)/2;
	}
};

class trapezio : public poligono {
	double base_maior;
	double base_menor;
	double altura;
public:
	trapezio(const string& c, double bma, double bme,
		 double a) : base_maior(bma),
			     base_menor(bme), altura(a) {
		cor = c;
	}

	double get_base_maior() {
		return base_maior;
	}

	void set_base_maior(double bm) {
		base_maior = bm;
	}

	double get_base_menor() {
		return base_menor;
	}

	void set_base_menor(double bm) {
		base_menor = bm;
	}

	double get_altura() {
		return altura;
	}

	void set_altura(double a) {
		altura = a;
	}

	double get_area() const {
		return ((base_maior + base_menor)*altura)/2;
	}

};

int main(void) {
	circulo cir1("AZUL", 10);
	retangulo ret1("AMARELO", 10, 20);
	triangulo tri1("VERMELHO", 20, 5);
	trapezio tra1("VERDE", 10, 20, 7);

	poligono* p1 = &cir1;
	poligono* p2 = &ret1;
	poligono* p3 = &tri1;
	poligono* p4 = &tra1;

	double soma_area = 0;

	soma_area = cir1.get_area() + ret1.get_area();
	soma_area += tri1.get_area() + tra1.get_area();

	cout << "Soma das areas: " << soma_area << endl;

	soma_area = p1->get_area() + p2->get_area();
	soma_area += p3->get_area() + p4->get_area();

	cout << "Soma das areas: " << soma_area << endl;

}





