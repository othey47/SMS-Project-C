#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

// Create varibales global to call it from anywhere
Student *students = NULL;
int student_count = 0;
int capacity = 0;


// init student system 
int initStudentSys()
{
    capacity = 1000;
    student_count = 0;

    students = malloc(capacity * sizeof(Student));

    if(students == NULL)
    {
        // Handle allocation failare
        printf("Allocation Failed\n");
        return 1;
    }
    else
    {
        printf("Allocation Success \n");
        return 0;
    }    
}

// Add Student
void addStudent()
{
    printf("[DEBUG] addStudent() called. \n");
    // TODO: Implement logic later
}

// List all Students
void listStudents()
{
    printf("[DEBUG] listStudents() called. \n");
    // TODO : Implement logic later
}

// Search Student 
void searchStuents()
{
    printf("[DEBUG] searchStuent called. \n");
    // TODO: Implement logic later
}

// Update Student 
void updateStudent()
{
    printf("[DEBUG] updateStudent() called.\n");
    // TODO: Implement logic later
}



