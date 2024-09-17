#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class pessoa {
	string nome;
	int idade;
public:
	pessoa() { }
	pessoa(const string& n, int i):nome(n),
				       idade(i) {}

	string get_nome() { return nome; }
	void set_nome(const string& n) {
		nome = n;
	}

	int get_idade() {
		return idade;
	}
	void set_idade(int i) {
		idade = i;
	}
};

class vendedor : public virtual pessoa {
	double meta;
public:
	vendedor(const string& n,
		 int i, double m):pessoa(n,i),
				  meta(m) {}
	double get_meta() {
		return meta;
	}
	void set_meta(double m) {
		meta = m;
	}
	void print_info() {
		cout << "vendedor(" << meta;
		cout << ")" << endl;
	}
};

class gerente : public virtual pessoa {
	string departamento;
public:
	gerente(const string& n,
		int i, const string& d):
				pessoa(n,i),
				departamento(d) {}
	string get_departamento() {
		return departamento;
	}
	void set_departamento(const string& d) {
		departamento = d;
	}
	void print_info() {
		cout << "gerente(";
		cout << departamento << ")" << endl;
	}
};

class vendedor_gerente : public vendedor,
			 public gerente {
public:
	vendedor_gerente(const string& n,
			 int i, double m,
			 const string& d):
				vendedor(n,i,m),
				gerente(n,i,d) {}

	void print_info() {
		cout << "------------" << endl;
		cout << "vendedor_gerente: " << endl;
		vendedor::print_info();
		gerente::print_info();
//		cout << get_meta() << ", ";
//		cout << get_departamento() << ")";
		cout << "------------";
		cout << endl;
	}

};

int main(void) {
	vendedor_gerente vg1("Joao", 30, 5000, "ELETRO");

	vg1.set_nome("Jose");

	cout << "Nome: " << vg1.get_nome() << endl;

	vg1.print_info();

	vg1.vendedor::print_info();

	vg1.gerente::print_info();

	return 0;

}








