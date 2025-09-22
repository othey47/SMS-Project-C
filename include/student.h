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

// Varibale for store name src of file :
extern const char *student_file; // declare it as extern

// Function Prototypes 
int initStudentSys();
void addStudent();
void listStudents();
int searchStudent();
void updateStudent();
void deleteStudent();
void freeStudents();

// Validation Functions Prototypes :
bool validate_id(unsigned id_input,int scanf_value);
bool validate_name(char *name);
bool validate_age(unsigned age_input, int scanf_value);
bool validate_grade(float grade_input, int scanf_value);

// File Handling Function Prototypes :
bool saveStudentsToFile(const char *student_file);
bool loadStudentsFromFile(const char *student_file);


#endif