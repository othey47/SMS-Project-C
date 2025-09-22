#include <stdio.h>
#include <stdbool.h>
#include "student.h"
#include "utils.h"

void show_menu() {
    printf("================= Menu-Driven System =================\n");
    printf(" 1. Add Student.                                      \n");
    printf(" 2. Display All Student.                              \n");
    printf(" 3. Search Student.                                   \n");
    printf(" 4. Update Student.                                   \n");
    printf(" 5. Delete Student.                                   \n");
    printf(" 0. Exit.                                             \n");
    printf("======================================================\n");
    printf("Enter your choice (0-5): ");
}

int main()
{

    int choice = -1;

    if (initStudentSys() != 0)
    {
        printf("The allocation failed, try again\n");
        return 1; // exit program
    }

    if (loadStudentsFromFile(student_file))
    {
        printf("Students loaded successfully.\n");
    }
    else
    {
        printf("No students loaded (file may not exist yet).\n");
    }

    

    // Menu loop: continues until user chooses to exit
    do {
        show_menu();
        scanf("%d", &choice);


        switch (choice) {
            case 1: // Add students
                addStudent();
                if (!saveStudentsToFile(student_file))
                    printf("Warning: Faild to save students!\n");
                
                break;

            case 2: // Display All Students
                listStudents();
                break;

            case 3: // Search Student
                searchStudent();
                break;

            case 4: // Update Student
                updateStudent();
                if (!saveStudentsToFile(student_file))
                    printf("Warning: Faild to save students!\n");
                
                break;

            case 5: // Delete Student
                deleteStudent();
                if (!saveStudentsToFile(student_file))
                    printf("Warning: Failed to save students!\n");
                
                break;

            case 0: // Exit program
                printf("Exit Program.......\n");    
                break;

            default: // Invalid input
                printf("Invalid input\n");
                break;
        }

    } while (choice != 0);  // Loop until exit

    return 0;
}

