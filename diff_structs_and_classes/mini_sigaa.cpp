#include <iostream>
#include <string.h>

#define NAME_SIZE 40
#define CLASS_SIZE 10

class person {
    private:
        int age;
        char name[NAME_SIZE];
    public:
        char* get_name() {
            return name;
        }

        void set_name(char* n) {
            strcpy(name, n);
        } 

        int get_age() {
            return age;
        }

        void set_age(int i) {
            if (i < 0 ||  i > 200) {
                printf("age invalid");
            }

            age = i;
        }
};

class student: public person {
    private:
        int registration;
        double cra;
    public:
        int get_registration() {
            return registration;
        }
        void set_registration(int m) {
            registration = m;
        }
        int get_cra() {
            return cra;
        }
        void set_cra(double c) {
            cra = c;
        }
};

class teacher: public person {
    int siape;
    int department;

    public:
        int get_siape() {
            return siape;
        }
        void set_siape(int m) {
            siape = m;
        }
        int get_department() {
            return department;
        }
        void set_department(double c) {
            department = c;
        }
};

class school_class {
    int classroom;
    int hoour;
    student* students[CLASS_SIZE];
    int length_students;
    teacher* prof;
};

int main() {
    student a1;
    teacher p1;

    a1.set_age(33);

    printf("%d", a1.get_age());

    return 0;
}