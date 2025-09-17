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

#endif