#include <iostream>
#include <string>

using std::cout;
using std::endl;

class animal {
	int age;
public:
	animal(int a) : age(a) {
		cout << "animal(" << age << ")" << endl;
	}

	int get_age() { return age; }

};

class mammal : virtual public animal {
	int coat;
public:
	mammal(int a, int c):animal(a), coat(c) {
		cout << "mammal(" << a << ", ";
		cout << coat << ")" << endl;
	}

	int get_coat() { return coat; }
};

class bird : virtual public animal {
	double wingspan;
public:
	bird(int a, double w):animal(a), wingspan(w) {
		cout << "bird(" << a << ", ";
		cout << wingspan << ")" << endl;
	}

	double get_wingspan() {
		return wingspan;
	}
};

class bat : public mammal, public bird {
	bool hematophagous;
public:
	bat(int a, int c, double w, bool h) : animal(a),
					      mammal(a,c),
					      bird(a,w),
					      hematophagous(h) {
		cout << "bat(" << a << ", " << c << ", ";
		cout << w << ", " << hematophagous << ")" << endl;

	}

	void print_info() {
                cout << "bat(" << get_age() << ", " << get_coat() << ", ";
                cout << get_wingspan() << ", " << hematophagous << ")";
		cout << endl;
	}
};

class vampire : public bat {
public:
	vampire(int a, int c, double w, bool h) : animal(a), bat(a,c,w,h) {
                cout << "vampire(" << a << ", " << c << ", ";
                cout << w << ", " << h << ")" << endl;

	}

};

int main(void) {
	vampire v1(1, 5, 10.5, false);

	animal* pa1 = &v1;
	mammal* pm1 = &v1;
	bird* pb1 = &v1;

	cout << endl;

	cout << pa1->get_age() << endl << endl;

	cout << pm1->get_age() << endl;
	cout << pm1->get_coat() << endl << endl;

	cout << pb1->get_age() << endl;
	cout << pb1->get_wingspan() << endl;

//	b1.print_info();

}
