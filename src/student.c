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

    // check if storage if full.
    if(student_count >= capacity)
    {
        printf("The space is full \n");
        return;
    }

    Student s;

    int i = student_count;


    printf("Enter information of student[%d]\n", i + 1);


    /* 1. ID :
        1. User Input :
        2. Error handling for input :
            -> Check if input is numeric .
            -> Check if input in range limits.
            -> duplicate ids, it's already exists.
    */
   int idvalid = 0; // to check if input true or false
   do
   {
        // Enter Input for ID :
        printf("Enter ID of student[%d]: \n", i + 1);
        int result = scanf("%u", &s.id);

        // Error handling for id :
        // => First : Check if input is numeric .
        if(result != 1)
        {
            printf("Invalid input!  Please enter a number id\n");
            clearInputBuffer();
            continue; // try again
        }

        clearInputBuffer();

        // => Second : check range limits :
        if (s.id > 1000) {
            printf("Invalid input! : ID must be between 0 and 1000.\n");
            continue;
        }
        // => Third: Check for duplicates (now we know s.id is valid)
        int isDuplicate = 0;
        
        for (int j = 0; j < student_count; j++) {
            if(s.id == students[j].id) {
                printf("ID already exists! Please choose a different ID.\n");
                isDuplicate = 1;
                break;
            }
        }

        if(isDuplicate) {
            continue; // Retry input.
        }


        idvalid = 1;

   } while (!idvalid);
   

   /* 2. Name :
        1. User Input :
        2. Error handling for input :
            -> Check if input is empty.
            -> Check if input is not letters.
            -> Check if range it's correct.
   */

    int nameValid = 0;
    do {

        // 1. User input :
        printf("Enter Name of student[%d]: ", i + 1);
        fgets(s.name, sizeof(s.name), stdin);
        trimNewline(s.name);
    
        // 2. Error handling for Name : 
        //  => First : Check if empty.
        if (strlen(s.name) == 0) {
            printf("Name cannot be empty!\n");
            continue;
        }
    
        // => Second : Check length.
        if (strlen(s.name) < 2 || strlen(s.name) > 49) {
            printf("Name must be between 2 and 49 characters.\n");
            continue;
        }
    
        // => Third : Check for valid characters only
        if (isValidName(s.name) != 0) {
            printf("Invalid characters! Use only letters, spaces, apostrophes, and hyphens.\n");
            continue;
        }
    
        nameValid = 1;
    
    } while (nameValid == 0);
     
    

    /* 3. Age :
        1. Input User :
        2. Error handling for input :
            -> check if input is numeric .
            -> check if input in range limits.

    */
    int agevalid = 0; // to check if input true or false :
    do
    {

        // 1. Enter Input for age :
        printf("Enter Age of student[%d]: \n", i + 1);      
        int result = scanf("%u", &s.age);
        
        // 2. Eror handling for age :
        // => First : Invalid non-sensible input :
        if(result != 1)
        {
            printf("Invalid input! Please enter a number.\n");
            clearInputBuffer();
            continue; // try again
        } 

        clearInputBuffer();

        // => Second : Check range limits :
        if(s.age < 7 || s.age > 30)
        {
            printf("Age must be between 7 and 30 \n");
            continue; // try again
        }

        agevalid = 1;

        
    } while (!agevalid);

    /* 4. Email :
        1. Input User :
        2. Error handling for input :
            -> check if input is Empty.
            -> check if input in range limits.
            -> check basic email format.
            -> check if email duplicate .
    */
    int emailValid = 0;
    do
    {
        // 1. Enter User :
        printf("Enter Email of student[%d]: \n", i + 1); 
        fgets(s.email, sizeof(s.email), stdin);
        trimNewline(s.email);
    
        // 2. Error handling for email :
        // => First : Check if empty :
        if(strlen(s.email) == 0)
        {
            printf("Email cannot be empty!\n");
            continue;
        }   

        // => Second : check length limits.
        if(strlen(s.email) > 50) // Adjust size as needed
        {
            printf("Email too long!. \n");
            continue;
        }

        // => Third : check basic email format.
        if (isValidEmail(s.email) != 0) // fixed
        {
            printf("Invalid email format!.\n");
            continue;
        }

        // => Fourth : Check for duplicates
        int isDuplicate = 0;
        for (int j = 0; j < student_count; j++) {
            if(strcmp(s.email, students[j].email) == 0) {
                printf("Email already exists! .\n");
                isDuplicate = 1;
                break;
            }
        }

        if(isDuplicate) {
            continue; // Retry input.
        }

        emailValid = 1; // all checks passed, exit loop

    } while (emailValid == 0);


    /* 1. Grade :
        1. User Input :
        2. Error handling for input :
            -> Check if input is numeric .
            -> Check if input in range limits.
    */
   int gradevalid = 0; // to check if input true or false
   do
   {
        // Enter Input for Grade :
        printf("Enter grade of student[%d]: \n", i + 1);
        int result = scanf("%f", &s.grade);

        // Error handling for Grade :
        // => First : Check if input is numeric .
        if(result != 1)
        {
            printf("Invalid input!  Please enter a number Grade\n");
            clearInputBuffer();
            continue; // try again
        }

        clearInputBuffer();

        // => Second : Check Range Limits :
        if(s.grade < 0.00 || s.grade > 20.00)
        {
            printf("Grade must be between 0.00 and 20.00\n");
            continue;
        }

        gradevalid = 1;

   } while (!gradevalid);

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

    unsigned search_id;
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
    int index = searchStudent();  // search and display student
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




