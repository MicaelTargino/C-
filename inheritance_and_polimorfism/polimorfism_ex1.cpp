#include <iostream>

using std::cout;
using std::endl;
using std::string;

class conta {
protected:
	double saldo;
public:
	conta(double s):saldo(s) {

	}

	void altera_saldo_mes() {

	}

	void sacar(double valor) {
		saldo -= valor;
	}

	void depositar(double valor) {
		saldo += valor;
	}

	void print_info() {
		cout << "saldo=" << saldo << endl;
	}
};

class conta_corrente : public conta {
	double limite;
	double valor_manutencao;
public:
	conta_corrente(double s, double l, double vm):
				 conta(s),
				 limite(l),
				 valor_manutencao(vm) {

	}
        void altera_saldo_mes() {
		saldo -= valor_manutencao;
        }

        void sacar(double valor) {
		if (valor <= (saldo+limite)) {
			saldo -= valor;
		} else {
			cout << "Saldo insuficiente!" << endl;
		}
        }

        void depositar(double valor) {
                saldo += valor;
        }

};

class conta_poupanca : public conta {
	double rendimento;
public:
	conta_poupanca(double s, double r):conta(s),
					   rendimento(r) {

	}
        void altera_saldo_mes() {
		saldo += (saldo*rendimento);
        }

        void sacar(double valor) {
                if (valor <= saldo) {
                        saldo -= valor;
                } else {
                        cout << "Saldo insuficiente!" << endl;
                }

        }

        void depositar(double valor) {
                saldo += valor;
        }
};

int main(void) {
	conta_corrente cc1(1000, 200, 20);
	conta_poupanca cp1(500, .01);

	conta* pc1;
	conta* pc2;

	pc1 = &cc1;
	pc2 = &cp1;

	pc1->altera_saldo_mes();
	pc2->altera_saldo_mes();


	pc1->print_info();
	pc2->print_info();



}
