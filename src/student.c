#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "utils.h"

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

    if(student_count >= capacity)
    {
        printf("The space is full \n");
        return;
    }

    Student s;

    int i = student_count;
    
    printf("Enter information of student[%d]\n", i + 1);

    printf("Enter ID of student[%d]: \n", i + 1);
    scanf("%d", &s.id);

    clearInputBuffer();

    printf("Enter Name of student[%d]: \n", i + 1);
    fgets(s.name, sizeof(s.name), stdin);
    trimNewline(s.name);
    

    printf("Enter Age of student[%d]: \n", i + 1);
    scanf("%d", &s.age);

    clearInputBuffer();

    printf("Enter email of student[%d]: \n", i + 1);
    fgets(s.email, sizeof(s.email), stdin);
    trimNewline(s.email);

    printf("Enter grade of student[%d]: \n", i + 1);
    scanf("%f", &s.grade);

    clearInputBuffer();

    students[student_count++] = s;
    
    printf("Student added successfully! \n");

}

// List all Students
void listStudents()
{
    if(student_count == 0)
    {
        printf("No students found. \n");
        return ;
    }

        // Table header
    printf("\n=============== Students Table ===============\n");
    printf("ID\t| Name\t\t\t| Age\t| Email\t\t\t| Grade\n");
    printf("-----------------------------------------------\n");

    // Print all students
    for (int i = 0; i < student_count; i++) 
    {
        Student s = students[i];

        printf("%d\t| %-16s\t| %d\t| %-16s\t| %.2f\t\n",
               s.id, s.name, s.age, s.email, s.grade);
    }

    printf("===============================================\n");

}

// Search Student 
int searchStudent()
{
        
    if(student_count  == 0)
    {
        printf("The student list is empty. \n");
        return -1;
    }

    int search_id;
    printf("Enter the ID for search \n");
    scanf("%d", &search_id);
    clearInputBuffer(); // clear leftover newline.

    // Loop through all students.

    for (int i = 0; i < student_count; i++) 
    {
        if (students[i].id == search_id) 
        {
            printf("\n============= Found Student =============\n");
            printf("ID: %d | Name: %s | Age: %d | Email: %s | Grade: %.2f\n", students[i].id, students[i].name, students[i].age, students[i].email, students[i].grade);

            printf("========================================\n");

            return i;  // Found
        }
    }
    printf("Student with ID %d not found. \n", search_id);
    return -1;  // Not found
}

// Update Student 
void updateStudent()
{
    int index = searchStudent();

    if (index == -1) {
        printf("The student record was not found.\n");
        return;
    }
    
    Student *s = &students[index];
    char buffer[100];

    printf("Updating information for student with ID: %d\n", students[index].id);

    // Update Name :
    printf("Current Name: %s\nEnter new Name (or press Enter to keep current): ", s->name);
    fgets(buffer, sizeof(buffer), stdin);
    trimNewline(buffer);
    if(strlen(buffer) > 0) {
        strncpy(s->name, buffer, sizeof(s->name));
    }
    
    
    // Update Age :
     printf("Current Age: %d\nEnter new Age (or -1 to keep current): ", s->age);
    int newAge;
    scanf("%d", &newAge);
    clearInputBuffer();
    if (newAge != -1)
    {
        s->age = newAge;
    }
    

    // Update Email :
    printf("Current Email: %s\nEnter new Email (or press Enter to keep current): ", s->email);
    fgets(buffer, sizeof(buffer), stdin);
    trimNewline(buffer);
    if (strlen(buffer) > 0)
    {
        strncpy(s->email, buffer, sizeof(s->email));
    }
    

    // Update Grade :
    printf("Current Grade: %.2f\nEnter new Grade (or -1 to keep current): ", s->grade);
    float newGrade;
    scanf("%f", &newGrade);    
    clearInputBuffer();
    if(newGrade != -1)
    {
        s->grade = newGrade;
    }

    printf("\nInformation updated successfully.\n");

}


// Delete Student
void deleteStudent()
{
    int index = searchStudents();  // search and display student
    if (index == -1) {
        printf("Student not found. Cannot delete.\n");
        return;
    }

    // Optional: confirm deletion
    char confirm;
    printf("Are you sure you want to delete student %s with ID %d? (y/n): ",
           students[index].name, students[index].id);
    scanf(" %c", &confirm);
    clearInputBuffer();

    if (confirm != 'y' && confirm != 'Y') {
        printf("Deletion cancelled.\n");
        return;
    }

    // Shift array elements to remove the student
    for (int i = index; i < student_count - 1; i++) {
        students[i] = students[i + 1];
    }

    student_count--;  // update the count

    printf("Student deleted successfully!\n");
}




