#include <stdio.h>
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
    

    // Menu loop: continues until user chooses to exit
    do {
        show_menu();
        scanf("%d", &choice);


        switch (choice) {
            case 1: // Add students
                addStudent();

                break;

            case 2: // Display All Students
                listStudents();
                break;

            case 3: // Search Student
                searchStudent();
                break;

            case 4: // Update Student
                updateStudent();
                break;

            case 5: // Delete Student
                deleteStudent();
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

