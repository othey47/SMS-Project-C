#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "student.h"
#include "utils.h"

// Create varibales global to call it from anywhere
Student *students = NULL;
#define DEFAULT_CAPACITY 1000
int capacity = DEFAULT_CAPACITY;
int student_count;


// init student system :
int initStudentSys()
{
    student_count = 0;

    // Check if array already allocated before allocating.
    if(students != NULL)
    {

        free(students);
        students = NULL; // reset array to NULL.
    }

    // check capacity size it's not 0 or negative.
    if(capacity > 0)
    {
        students = malloc(capacity * sizeof(Student));
    }
    else
    {
        printf("Error: capacity must be greater than 0\n");
        return(EXIT_FAILURE);
    }

    // check students it's allocated or still Null.
    if(students == NULL)
    {
        //Handle allocation failure.
        printf("Allocation Failed\n");
        return(EXIT_FAILURE);
    }
    else
    {   
        // Handle allocation success.
        printf("Allocation Success\n");
        return(EXIT_SUCCESS);
    }    
}

// validate id input :
bool validate_id(unsigned id_input,int scanf_value)
{
    /* 1. ID :
        1. User Input :
        2. Error handling for input :
            -> Check if input is numeric .
            -> Check if input in range limits.
            -> duplicate ids, it's already exists.
    */

    // => Fisrt : Check if input is numeric.
    if (scanf_value != 1)
    {
        printf("Invalid input!  Please enter a number id\n");
        return false; // not valid 
    }
    

    // => Second : Check if input is range limits .
    if(id_input > 1000)
    {
        printf("Invalid input! : ID must be between 0 and 1000.\n");
        return false; // not valid
    }


    // => Third: Check for duplicates (now we know s.id is valid)
    for (int j = 0; j < student_count; j++) {
        if(id_input == students[j].id) {
            printf("ID already exists! Please choose a different ID.\n");               
            return false; // not valid
        }
    }

    return true; // valid

}

// validate name input :
bool validate_name(char *name)
{
    //  => First : Check if empty.
    if (strlen(name) == 0) {
        printf("Name cannot be empty!\n");
        return false; // not valid
    }

    // => Second : Check length.
    if (strlen(name) < 2 || strlen(name) > 49) {
        printf("Name must be between 2 and 49 characters.\n");
        return false; // not valid
    } 

    // => Third : Check for valid characters only
    if (isValidName(name) != true) {
        printf("Invalid characters! Use only letters, spaces, apostrophes, and hyphens.\n");
        return false; // notvalid
    }

    return true; // valid

}

// validate age input :
bool validate_age(unsigned age_input, int scanf_value)
{
    
    // => First : check if input numeric :
    if(scanf_value != 1)
    {
        printf("Invalid input! Please enter a number.\n");
        return false;
    }
    
    // => Second : check if input range limits.
    
    if(age_input < 7 || age_input > 30)
    {
        printf("Age must be between 7 and 30 \n");
        return false; // not valid
    }

    return true;
}

// validate email input :
bool validate_email(char *email)
{
    // => First : Check if empty :
    if(strlen(email) == 0)
    {
        printf("Email cannot be empty!\n");
        return false; // not valid
    }

    // => Second : check length limits.
    if(strlen(email) > 50) // Adjust size as needed
    {
        printf("Email too long!. \n");
        return false;  // not valid
    }

    // => Third : check basic email format.
    if (!isValidEmail(email)) // fixed
    {
        printf("Invalid email format!.\n");
        return false; // not valid
    }

    // => Fourth : Check for duplicates
    for (int j = 0; j < student_count; j++) {
        if(strcmp(email, students[j].email) == 0) {
            printf("Email already exists! .\n");
            return false;
       }
    }

    return true; // valid
    
}

// validate grade input :
bool validate_grade(float grade_input, int scanf_value)
{
    // => First : Check if input is numeric .
    if(scanf_value != 1)
    {
       printf("Invalid input!  Please enter a number Grade\n");
       return false; // not valid
    }

    // => Second : Check Range Limits :
    if(grade_input < 0.00 || grade_input > 20.00)
    {
        printf("Grade must be between 0.00 and 20.00\n");
        return false; // not valid
    }

}

// Add Student :
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
   bool idvalid = false; // to check if input true or false
   do
   {
        // Enter input for id :
        printf("Enter ID of student[%d]: \n", i + 1);

        int scanf_value = scanf("%u", &s.id);

        clearInputBuffer();

        // check validition for input :
        idvalid = validate_id(s.id, scanf_value);
        
   } while (!idvalid);
   

   /* 2. Name :
        1. User Input :
        2. Error handling for input :
            -> Check if input is empty.
            -> Check if input is not letters.
            -> Check if range it's correct.
   */
    bool nameValid = false;
    do {

        // Enter input for name :
        printf("Enter Name of student[%d]: ", i + 1);
        fgets(s.name, sizeof(s.name), stdin);
        trimNewline(s.name);

        // check validation for input : 
        nameValid = validate_name(s.name);

    
    } while (!nameValid);
     
    

    /* 3. Age :
        1. Input User :
        2. Error handling for input :
            -> check if input is numeric .
            -> check if input in range limits.

    */
    bool agevalid = false; // to check if input true or false :
    do
    {

        // Enter input for age :
        printf("Enter Age of student[%d]: \n", i + 1);

        int scanf_value = scanf("%u", &s.age);
        

        clearInputBuffer();

        // check for validation of input :
        agevalid = validate_age(s.age, scanf_value);

        
    } while (!agevalid);



    /* 4. Email :
        1. Input User :
        2. Error handling for input :
            -> check if input is Empty.
            -> check if input in range limits.
            -> check basic email format.
            -> check if email duplicate .
    */
    bool emailValid = false; // check if input  true or false.
    do
    {
        //  Enter input for email :
        printf("Enter Email of student[%d]: \n", i + 1); 
        fgets(s.email, sizeof(s.email), stdin);
        trimNewline(s.email);
        
        // check validation of input :
        emailValid = validate_email(s.email);

    } while (!emailValid);


    /* 5. Grade :
        1. User Input :
        2. Error handling for input :
            -> Check if input is numeric .
            -> Check if input in range limits.
    */
   bool gradevalid = false; // to check if input true or false
   do
   {
        // Enter input for grade :
        printf("Enter grade of student[%d]: \n", i + 1);
        int scanf_value = scanf("%f", &s.grade);

        clearInputBuffer();

        // check validation of input :
        gradevalid = validate_grade(s.grade, scanf_value);

   } while (!gradevalid);

    students[student_count++] = s;

    printf("Student added successfully! \n");

}

// List all students :
void listStudents()
{
    // Displays a formatted table of all students. Returns nothing.
    if (students == NULL || student_count < 0) {
        printf("Error: Student data is invalid.\n");
        return;
    }
    if(student_count == 0)
    {
        printf("No students found.\n");
        return;
    }   
    
    // Table header
    printf("\n=============================== Students Table ================================\n");
    printf("%-5s | %-49.49s | %-3s | %-49.49s | %-6s\n",          // All %s for strings
           "ID", "Name", "Age", "Email", "Grade");

    int line_length = 5 + 3 + 49 + 3 + 3 + 3 + 49 + 3 + 6; // sum of column widths + spaces/pipes
    for (int i = 0; i < line_length; i++) putchar('-');
    putchar('\n');

    // Print all students
    for (int i = 0; i < student_count; i++) 
    {

        printf("%-5u | %-49.49s | %-3u | %-49.49s | %6.2f\n",  // Match data types
               students[i].id, students[i].name, students[i].age, students[i].email, students[i].grade);
    }

    for (int i = 0; i < line_length; i++) putchar('=');
    putchar('\n');
    printf("Total students: %d\n", student_count);
}

// Search Student 
int searchStudent()
{
    // check if student is empty , check is student record full.
    if (students == NULL || student_count > capacity) // capacity = 1000;
    {
        printf("Error : Student data is invalid");
        return -1;
    }

    // check is student counter it's empty.
    if(student_count  <= 0)
    {
        printf("The student list is empty. \n");
        return -1;
    }

    // check input failure :
    unsigned search_id;

    printf("Enter the ID for search \n");
    if(scanf("%u", &search_id) != 1 || search_id == 0)
    {
        printf("\nError: invalid ID input. \n");
        clearInputBuffer(); // clear leftover newline.
        return -1;
    }

    // Loop through all students.

    for (int i = 0; i < student_count; i++) 
    {
        if (students[i].id == search_id) 
        {
            printf("\n======================= Found Student ======================\n");
            printf("ID: %u | Name: %s | Age: %u | Email: %s | Grade: %.2f\n", students[i].id, students[i].name, students[i].age, students[i].email, students[i].grade);

            printf("==============================================================\n");

            return i;  // Found
        }
    }
    printf("Student with ID %u not found. \n", search_id);
    return -1;  // Not found
}


// Update Student 
void updateStudent()
{
    // Search for the student by ID :
    int index = searchStudent();
    
    // check if the student record exists.
    if (index == -1) {
        printf("The student record was not found.\n");
        return;
    }
    
    // Pointer to the student to simplify access.
    Student *s = &students[index];
    char buffer[100]; // Temporary buffer for string input.

    printf("Updating information for student with ID: %d\n", students[index].id);

    // 2.Update Name :
    // show current name and prompt for new input.
    // Pressing Enter keeps the current name.
    printf("Current Name: %s\nEnter new Name (or press Enter to keep current): ", s->name);
    fgets(buffer, sizeof(buffer), stdin);
    // Remove trailing newline from fgets.
    trimNewline(buffer);
    if(strlen(buffer) > 0) {
        // copy new name safely, ensuring null-termination.
        strncpy(s->name, buffer, sizeof(s->name) -1);
        s->name[sizeof(s->name) - 1] = '\0';
    }
    
    
    // 3.Update Age :
    // Show current age and prompt for new input.
    // Entering a number >0 updates the age; otherwise, keeps the current value.
    printf("Current Age: %d\nEnter new Age (or -1 to keep current): ", s->age);
    int newAge;
    scanf("%d", &newAge);
    // clear leftover input from stdin.
    clearInputBuffer();
    if(newAge > 0) s->age = newAge;

    

    // 4.Update Email :
    // Show current email and prompt for new input.
    // Pressing Enter keeps the current email.
    printf("Current Email: %s\nEnter new Email (or press Enter to keep current): ", s->email);
    fgets(buffer, sizeof(buffer), stdin);
    trimNewline(buffer);
    if (strlen(buffer) > 0)
    {
        // Copy new email safelt, ensuring null-termination.
        strncpy(s->email, buffer, sizeof(s->email) - 1);
        s->email[sizeof(s->email) - 1] = '\0';
    }
    

    // 5.Update Grade :
    // Show current grade and prompt for new input.
    // Entering a number between 0 and 20 updates the grade; otherwise, keeps the current value.
    printf("Current Grade: %.2f\nEnter new Grade (or -1 to keep current): ", s->grade);
    float newGrade;
    scanf("%f", &newGrade);    
    clearInputBuffer();
    if(newGrade >= 0.0 && newGrade <= 20.00) s->grade = newGrade;
    // Confirm update completion.
    printf("\nInformation updated successfully.\n");

}


// Delete Student
void deleteStudent()
{
    // Search for the student by ID :
    int index = searchStudent();

    // check if the student record exists.
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

void freeStudents()
{
    if (students == NULL) return;

    // Only free the array if it was dynamically allocated
    free(students);
    students = NULL;
    student_count = 0;
    capacity = 0;

    printf("All student records have been freed from memory.\n");
}
