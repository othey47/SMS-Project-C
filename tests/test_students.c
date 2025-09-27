#include "../include/student.h"
#include <stdio.h>

int main() {
    Student students[10];
    int count = 0;

    // Directly add students without scanf
    students[0] = (Student){3, "Khadija", 23, "KH@example.com", 12.21f};
    count++;

    // Display
    printf("ID: %u, Name: %s, Age: %u, Email: %s, Grade: %.2f\n",
           students[0].id, students[0].name, students[0].age,
           students[0].email, students[0].grade);

    return 0;
}
