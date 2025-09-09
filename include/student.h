#ifndef STUDENT_H
#define STUDENT_H

typedef struct student 
{
    int id; 
    char name[50];
    int age;
    char email[50];
    float grade;
} Student;

// Function Prototypes 

void addStudent();
void listStudents();
void searchStudent();
void updateStudent();
void deleteStudent();

#endif