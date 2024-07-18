#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define NAME_SIZE 40
#define CLASS_SIZE 10

typedef struct {
    char name[NAME_SIZE];
    int age;
} t_person;

typedef struct {
    t_person p;
    int registration;
    double cra;
} t_students;

typedef struct {
    t_person p;
    int registration;
    int department
} t_teacher;

typedef struct {
    int classroom;
    int hour;
    t_students* students[CLASS_SIZE];
    t_teacher* teacher;
} t_class;


int main() {
    t_students a1;
    t_teacher p1;

    strcpy(&p1.p.name, 'Ana Silva');
    p1.department = 10;
    p1.p.age = 40;



    return 0;
}