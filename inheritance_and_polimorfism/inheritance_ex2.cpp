#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

class pessoa {
	int idade;
	string nome;
public:
	pessoa(int i, const string& n) : idade(i), nome(n) {
		cout << "pessoa()" << endl;
	}
	~pessoa() { cout << "~pessoa()" << endl; }
	int get_idade() const { return idade; }
	void set_idade(int i) { idade = i; }
	string get_nome() const { return nome; }
	void set_nome(const string& s) { nome = s; }
	void print_info() {
		cout << "pessoa(" << nome << ", ";
		cout << idade << ")" << endl;
	}
};

class professor : public pessoa {
	string titulacao;
	int ano_titu;
public:
	professor(int i, const string& n,
		  const string& t, int a) : pessoa(i,n),
		   			    titulacao(t),
					    ano_titu(a) {
		cout << "professor()" << endl;
	}
	~professor() { cout << "~professor()" << endl; }

	string get_titulacao() const { return titulacao; }
	void set_titulacao(const string& t) { titulacao = t; }
	int get_ano_titulacao() const { return ano_titu; }
	void set_ano_titulacao(int a) { ano_titu = a; }
	void print_info() {
		cout << "professor(" << get_idade();
		cout << ", " << get_nome() << ", ";
		cout << titulacao << ", " << ano_titu;
		cout << ")" << endl;
	}
};

class aluno : public pessoa {
	double cra;
	int matricula;
public:
	aluno(int i, const string& n,
		       double c, int m) : pessoa(i, n),
					  cra(c),
					  matricula(m) { 
		cout << "aluno()" << endl;
	}
	~aluno() { cout << "~aluno()" << endl; }
	double get_cra() const { return cra; }
	void set_cra(double c) { cra = c; }
	int get_matricula() const { return matricula; }
	void set_matricula(int m) { matricula = m; }
        void print_info() {
                cout << "aluno(" << get_idade();
                cout << ", " << get_nome() << ", ";
                cout << cra << ", " << matricula;
                cout << ")" << endl;
        }

};

class tecnico : public pessoa {
	string departamento;
	string funcao;
public:
	tecnico(int i, const string& n,
		       const string& d,
		       const string& f) : pessoa(i,n),
					  departamento(d),
					  funcao(f) {
		cout << "tecnico() " << endl;
	}
	~tecnico() { cout << "~tecnico()" << endl; }
	string get_departamento() const { return departamento; }
	void set_departamento(const string& d) {
		departamento = d;
	}
	string get_funcao() const { return funcao; }
	void set_funcao(const string& f) { funcao = f; }
        void print_info() {
                cout << "tecnico(" << get_idade();
                cout << ", " << get_nome() << ", ";
                cout << departamento << ", " << funcao;
                cout << ")" << endl;
        }


};

class turma {
	professor* prof;
	vector<aluno*> lista_alunos;
public:
	turma(professor* p) : prof(p) {
		cout << "turma()" << endl;
	}
	professor* get_professor() const { return prof; }
	void set_professor(professor* p) { prof = p; }
	void add_aluno(aluno* a) {
		lista_alunos.push_back(a);
	}
	void print_info() {
		cout << "turma:" << endl;
		cout << "professor: ";
		prof->print_info();
		cout << "alunos: ";
		for (auto i = lista_alunos.begin();
			  i != lista_alunos.end();
			  ++i) {
			(*i)->print_info();
		}
	}
};

class rh {
	vector<pessoa*> pessoal;
public:
	void add_pessoa(pessoa* p) {
		pessoal.push_back(p);
	}
	void print_info() {
		cout << "pessoal: " << endl;
		for (auto i = pessoal.begin();
                          i != pessoal.end();
                          ++i) {
                        (*i)->print_info();
                }
	}

};

int main(void) {
	pessoa p1(38, "Ana Silva");
	professor pr1(44, "Joao Ferreira", "Doutor", 2008);
	aluno al1(18, "Maria Fernandes", 9.5, 100123123);
	tecnico te1(35, "Joao da Silva", "DSC", "Assessor");

	rh rh1;

	rh1.add_pessoa(&p1);
	rh1.add_pessoa(&pr1);
	rh1.add_pessoa(&al1);
	rh1.add_pessoa(&te1);

	rh1.print_info();

/*
	turma tu1(&pr1);

	pr1.set_idade(41);

	tu1.add_aluno(&al1);
	tu1.print_info();
*/

/*
	p1.print_info();
	pr1.print_info();
	al1.print_info();
	te1.print_info();
*/
	return 0;
}
