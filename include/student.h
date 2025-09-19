#ifndef STUDENT_H
#define STUDENT_H

typedef struct student 
{
    unsigned int id; 
    char name[50];
    unsigned age;
    char email[50];
    float grade;
} Student;

// Function Prototypes 
int initStudentSys();
void addStudent();
void listStudents();
int searchStudent();
void updateStudent();
void deleteStudent();
void freeStudents();

// Validation Functions Prototypes :

// validate id input :
bool validate_id(unsigned id_input,int scanf_value);

// validate name input :
bool validate_name(char *name);

// validate age input :
bool validate_age(unsigned age_input, int scanf_value);

// validate grade input :
bool validate_grade(float grade_input, int scanf_value);


#endif