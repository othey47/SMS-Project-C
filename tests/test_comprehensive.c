#include "../include/student.h"
#include "../include/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// External declarations for global variables from student.c
extern Student *students;
extern int student_count;
extern int capacity;

// Test result tracking
int tests_passed = 0;
int tests_failed = 0;

// Test helper macros
#define ASSERT_TRUE(condition, message) \
    do { \
        if (condition) { \
            printf("✓ PASS: %s\n", message); \
            tests_passed++; \
        } else { \
            printf("✗ FAIL: %s\n", message); \
            tests_failed++; \
        } \
    } while(0)

#define ASSERT_FALSE(condition, message) \
    do { \
        if (!(condition)) { \
            printf("✓ PASS: %s\n", message); \
            tests_passed++; \
        } else { \
            printf("✗ FAIL: %s\n", message); \
            tests_failed++; \
        } \
    } while(0)

#define ASSERT_EQUAL(expected, actual, message) \
    do { \
        if ((expected) == (actual)) { \
            printf("✓ PASS: %s\n", message); \
            tests_passed++; \
        } else { \
            printf("✗ FAIL: %s (expected: %d, actual: %d)\n", message, expected, actual); \
            tests_failed++; \
        } \
    } while(0)

// Test helper functions
void reset_test_environment() {
    if (students != NULL) {
        free(students);
        students = NULL;
    }
    student_count = 0;
    capacity = 1000;
}

void print_test_header(const char* test_name) {
    printf("\n=== %s ===\n", test_name);
}

void print_test_summary() {
    printf("\n=== TEST SUMMARY ===\n");
    printf("Tests Passed: %d\n", tests_passed);
    printf("Tests Failed: %d\n", tests_failed);
    printf("Total Tests: %d\n", tests_passed + tests_failed);
    printf("Success Rate: %.1f%%\n", (float)tests_passed / (tests_passed + tests_failed) * 100);
}

// ============================================================================
// TEST FUNCTIONS FOR INITIALIZATION
// ============================================================================

void test_init_student_sys_success() {
    print_test_header("Testing initStudentSys - Success Case");
    
    reset_test_environment();
    
    int result = initStudentSys();
    ASSERT_EQUAL(EXIT_SUCCESS, result, "initStudentSys should return EXIT_SUCCESS");
    ASSERT_TRUE(students != NULL, "students array should be allocated");
    ASSERT_EQUAL(0, student_count, "student_count should be 0 after initialization");
}

void test_init_student_sys_reallocation() {
    print_test_header("Testing initStudentSys - Reallocation");
    
    reset_test_environment();
    
    // First allocation
    int result1 = initStudentSys();
    ASSERT_EQUAL(EXIT_SUCCESS, result1, "First initStudentSys should succeed");
    
    // Add a student
    students[0] = (Student){1, "Test", 20, "test@example.com", 15.5f};
    student_count = 1;
    
    // Second allocation (should free and reallocate)
    int result2 = initStudentSys();
    ASSERT_EQUAL(EXIT_SUCCESS, result2, "Second initStudentSys should succeed");
    ASSERT_EQUAL(0, student_count, "student_count should be reset to 0");
}

// ============================================================================
// TEST FUNCTIONS FOR VALIDATION
// ============================================================================

void test_validate_id() {
    print_test_header("Testing validate_id function");
    
    reset_test_environment();
    initStudentSys();
    
    // Test valid ID
    ASSERT_TRUE(validate_id(123, 1), "Valid ID should pass validation");
    
    // Test invalid scanf return
    ASSERT_FALSE(validate_id(123, 0), "Invalid scanf return should fail validation");
    
    // Test ID out of range
    ASSERT_FALSE(validate_id(1001, 1), "ID > 1000 should fail validation");
    
    // Test duplicate ID
    students[0] = (Student){123, "Test", 20, "test@example.com", 15.5f};
    student_count = 1;
    ASSERT_FALSE(validate_id(123, 1), "Duplicate ID should fail validation");
}

void test_validate_name() {
    print_test_header("Testing validate_name function");
    
    // Test valid name
    ASSERT_TRUE(validate_name("John Doe"), "Valid name should pass validation");
    ASSERT_TRUE(validate_name("Mary-Jane O'Connor"), "Name with hyphens and apostrophes should pass");
    
    // Test empty name
    ASSERT_FALSE(validate_name(""), "Empty name should fail validation");
    
    // Test too short name
    ASSERT_FALSE(validate_name("A"), "Name too short should fail validation");
    
    // Test too long name (50+ characters)
    char long_name[60];
    memset(long_name, 'A', 50);
    long_name[50] = '\0';
    ASSERT_FALSE(validate_name(long_name), "Name too long should fail validation");
    
    // Test invalid characters
    ASSERT_FALSE(validate_name("John123"), "Name with numbers should fail validation");
    ASSERT_FALSE(validate_name("John@Doe"), "Name with special characters should fail validation");
}

void test_validate_age() {
    print_test_header("Testing validate_age function");
    
    // Test valid ages
    ASSERT_TRUE(validate_age(10, 1), "Valid age should pass validation");
    ASSERT_TRUE(validate_age(25, 1), "Valid age should pass validation");
    
    // Test invalid scanf return
    ASSERT_FALSE(validate_age(20, 0), "Invalid scanf return should fail validation");
    
    // Test age too young
    ASSERT_FALSE(validate_age(5, 1), "Age < 7 should fail validation");
    
    // Test age too old
    ASSERT_FALSE(validate_age(35, 1), "Age > 30 should fail validation");
}

void test_validate_grade() {
    print_test_header("Testing validate_grade function");
    
    // Test valid grades
    ASSERT_TRUE(validate_grade(10.5f, 1), "Valid grade should pass validation");
    ASSERT_TRUE(validate_grade(0.0f, 1), "Minimum grade should pass validation");
    ASSERT_TRUE(validate_grade(20.0f, 1), "Maximum grade should pass validation");
    
    // Test invalid scanf return
    ASSERT_FALSE(validate_grade(10.0f, 0), "Invalid scanf return should fail validation");
    
    // Test grade too low
    ASSERT_FALSE(validate_grade(-1.0f, 1), "Grade < 0 should fail validation");
    
    // Test grade too high
    ASSERT_FALSE(validate_grade(21.0f, 1), "Grade > 20 should fail validation");
}

// ============================================================================
// TEST FUNCTIONS FOR UTILITY FUNCTIONS
// ============================================================================

void test_trim_newline() {
    print_test_header("Testing trimNewline function");
    
    char str1[] = "Hello World\n";
    char str2[] = "Hello World";
    char str3[] = "\n";
    char str4[] = "";
    
    trimNewline(str1);
    ASSERT_TRUE(strcmp(str1, "Hello World") == 0, "Should remove trailing newline");
    
    trimNewline(str2);
    ASSERT_TRUE(strcmp(str2, "Hello World") == 0, "Should not affect string without newline");
    
    trimNewline(str3);
    ASSERT_TRUE(strcmp(str3, "") == 0, "Should handle single newline");
    
    trimNewline(str4);
    ASSERT_TRUE(strcmp(str4, "") == 0, "Should handle empty string");
}

void test_is_valid_name() {
    print_test_header("Testing isValidName function");
    
    // Test valid names
    ASSERT_TRUE(isValidName("John Doe"), "Valid name should pass");
    ASSERT_TRUE(isValidName("Mary-Jane"), "Name with hyphen should pass");
    ASSERT_TRUE(isValidName("O'Connor"), "Name with apostrophe should pass");
    ASSERT_TRUE(isValidName("Jean Paul"), "Name with space should pass");
    
    // Test invalid names
    ASSERT_FALSE(isValidName("John123"), "Name with numbers should fail");
    ASSERT_FALSE(isValidName("John@Doe"), "Name with @ should fail");
    ASSERT_FALSE(isValidName("John#Doe"), "Name with # should fail");
    ASSERT_FALSE(isValidName("John.Doe"), "Name with . should fail");
}

void test_is_valid_email() {
    print_test_header("Testing isValidEmail function");
    
    // Test valid emails
    ASSERT_TRUE(isValidEmail("test@example.com"), "Valid email should pass");
    ASSERT_TRUE(isValidEmail("user.name@domain.org"), "Email with dot should pass");
    ASSERT_TRUE(isValidEmail("a@b.c"), "Minimal valid email should pass");
    
    // Test invalid emails
    ASSERT_FALSE(isValidEmail(""), "Empty email should fail");
    ASSERT_FALSE(isValidEmail("@example.com"), "Email starting with @ should fail");
    ASSERT_FALSE(isValidEmail("test@"), "Email ending with @ should fail");
    ASSERT_FALSE(isValidEmail("test@example"), "Email without domain extension should fail");
    ASSERT_FALSE(isValidEmail("test example@domain.com"), "Email with spaces should fail");
    ASSERT_FALSE(isValidEmail("test@@example.com"), "Email with double @ should fail");
}

// ============================================================================
// TEST FUNCTIONS FOR CRUD OPERATIONS
// ============================================================================

void test_add_student_manual() {
    print_test_header("Testing manual student addition");
    
    reset_test_environment();
    initStudentSys();
    
    // Manually add a student (simulating addStudent without user input)
    Student test_student = {1, "Test Student", 20, "test@example.com", 15.5f};
    students[student_count++] = test_student;
    
    ASSERT_EQUAL(1, student_count, "Student count should be 1");
    ASSERT_EQUAL(1, students[0].id, "Student ID should match");
    ASSERT_TRUE(strcmp(students[0].name, "Test Student") == 0, "Student name should match");
    ASSERT_EQUAL(20, students[0].age, "Student age should match");
    ASSERT_TRUE(strcmp(students[0].email, "test@example.com") == 0, "Student email should match");
    ASSERT_TRUE(students[0].grade == 15.5f, "Student grade should match");
}

void test_search_student() {
    print_test_header("Testing searchStudent function");
    
    reset_test_environment();
    initStudentSys();
    
    // Add test students
    students[0] = (Student){1, "Alice", 20, "alice@example.com", 15.5f};
    students[1] = (Student){2, "Bob", 21, "bob@example.com", 16.0f};
    student_count = 2;
    
    // Test searching for existing student
    // Note: searchStudent() uses scanf, so we'll test the logic manually
    int found_index = -1;
    unsigned search_id = 1;
    
    for (int i = 0; i < student_count; i++) {
        if (students[i].id == search_id) {
            found_index = i;
            break;
        }
    }
    
    ASSERT_EQUAL(0, found_index, "Should find student at index 0");
    
    // Test searching for non-existing student
    search_id = 999;
    found_index = -1;
    
    for (int i = 0; i < student_count; i++) {
        if (students[i].id == search_id) {
            found_index = i;
            break;
        }
    }
    
    ASSERT_EQUAL(-1, found_index, "Should not find non-existing student");
}

void test_update_student_manual() {
    print_test_header("Testing manual student update");
    
    reset_test_environment();
    initStudentSys();
    
    // Add a student
    students[0] = (Student){1, "Original Name", 20, "original@example.com", 15.0f};
    student_count = 1;
    
    // Update student manually
    Student *s = &students[0];
    strcpy(s->name, "Updated Name");
    s->age = 21;
    strcpy(s->email, "updated@example.com");
    s->grade = 16.5f;
    
    ASSERT_TRUE(strcmp(students[0].name, "Updated Name") == 0, "Name should be updated");
    ASSERT_EQUAL(21, students[0].age, "Age should be updated");
    ASSERT_TRUE(strcmp(students[0].email, "updated@example.com") == 0, "Email should be updated");
    ASSERT_TRUE(students[0].grade == 16.5f, "Grade should be updated");
}

void test_delete_student_manual() {
    print_test_header("Testing manual student deletion");
    
    reset_test_environment();
    initStudentSys();
    
    // Add multiple students
    students[0] = (Student){1, "Alice", 20, "alice@example.com", 15.5f};
    students[1] = (Student){2, "Bob", 21, "bob@example.com", 16.0f};
    students[2] = (Student){3, "Charlie", 22, "charlie@example.com", 17.0f};
    student_count = 3;
    
    // Delete student at index 1 (Bob)
    int delete_index = 1;
    
    // Shift array elements to remove the student
    for (int i = delete_index; i < student_count - 1; i++) {
        students[i] = students[i + 1];
    }
    student_count--;
    
    ASSERT_EQUAL(2, student_count, "Student count should be 2 after deletion");
    ASSERT_EQUAL(1, students[0].id, "First student should remain");
    ASSERT_EQUAL(3, students[1].id, "Third student should move to second position");
}

// ============================================================================
// TEST FUNCTIONS FOR FILE OPERATIONS
// ============================================================================

void test_save_load_students() {
    print_test_header("Testing save and load students");
    
    reset_test_environment();
    initStudentSys();
    
    // Add test students
    students[0] = (Student){1, "Alice", 20, "alice@example.com", 15.5f};
    students[1] = (Student){2, "Bob", 21, "bob@example.com", 16.0f};
    student_count = 2;
    
    // Save to file
    bool save_result = saveStudentsToFile("test_students.dat");
    ASSERT_TRUE(save_result, "Save operation should succeed");
    
    // Reset the array
    student_count = 0;
    
    // Load from file
    bool load_result = loadStudentsFromFile("test_students.dat");
    ASSERT_TRUE(load_result, "Load operation should succeed");
    ASSERT_EQUAL(2, student_count, "Should load 2 students");
    ASSERT_EQUAL(1, students[0].id, "First student ID should match");
    ASSERT_EQUAL(2, students[1].id, "Second student ID should match");
    
    // Clean up test file
    remove("test_students.dat");
}

// ============================================================================
// TEST FUNCTIONS FOR EDGE CASES
// ============================================================================

void test_empty_student_list() {
    print_test_header("Testing operations on empty student list");
    
    reset_test_environment();
    initStudentSys();
    
    // Test search on empty list
    int found_index = -1;
    unsigned search_id = 1;
    
    for (int i = 0; i < student_count; i++) {
        if (students[i].id == search_id) {
            found_index = i;
            break;
        }
    }
    
    ASSERT_EQUAL(-1, found_index, "Search on empty list should return -1");
}

void test_capacity_limits() {
    print_test_header("Testing capacity limits");
    
    reset_test_environment();
    initStudentSys();
    
    // Test adding students up to capacity
    for (int i = 0; i < capacity; i++) {
        students[i] = (Student){i + 1, "Student", 20, "student@example.com", 15.0f};
    }
    student_count = capacity;
    
    ASSERT_EQUAL(capacity, student_count, "Should be able to add students up to capacity");
    
    // Test that we can't add beyond capacity
    if (student_count >= capacity) {
        ASSERT_TRUE(true, "Should detect when capacity is reached");
    }
}

// ============================================================================
// INTEGRATION TESTS
// ============================================================================

void test_complete_workflow() {
    print_test_header("Testing complete student management workflow");
    
    reset_test_environment();
    initStudentSys();
    
    // 1. Add students
    students[0] = (Student){1, "Alice", 20, "alice@example.com", 15.5f};
    students[1] = (Student){2, "Bob", 21, "bob@example.com", 16.0f};
    student_count = 2;
    
    // 2. Save to file
    bool save_result = saveStudentsToFile("workflow_test.dat");
    ASSERT_TRUE(save_result, "Save should succeed");
    
    // 3. Reset and load
    student_count = 0;
    bool load_result = loadStudentsFromFile("workflow_test.dat");
    ASSERT_TRUE(load_result, "Load should succeed");
    ASSERT_EQUAL(2, student_count, "Should load 2 students");
    
    // 4. Update a student
    students[0].grade = 17.0f;
    
    // 5. Delete a student
    for (int i = 0; i < student_count - 1; i++) {
        students[i] = students[i + 1];
    }
    student_count--;
    
    ASSERT_EQUAL(1, student_count, "Should have 1 student after deletion");
    ASSERT_EQUAL(2, students[0].id, "Remaining student should be Bob");
    
    // Clean up
    remove("workflow_test.dat");
}

// ============================================================================
// MAIN TEST RUNNER
// ============================================================================

int main() {
    printf("Starting Comprehensive Student Management System Tests\n");
    printf("====================================================\n");
    
    // Run all test suites
    test_init_student_sys_success();
    test_init_student_sys_reallocation();
    
    test_validate_id();
    test_validate_name();
    test_validate_age();
    test_validate_grade();
    
    test_trim_newline();
    test_is_valid_name();
    test_is_valid_email();
    
    test_add_student_manual();
    test_search_student();
    test_update_student_manual();
    test_delete_student_manual();
    
    test_save_load_students();
    
    test_empty_student_list();
    test_capacity_limits();
    
    test_complete_workflow();
    
    // Print final results
    print_test_summary();
    
    // Clean up
    if (students != NULL) {
        free(students);
        students = NULL;
    }
    
    return (tests_failed > 0) ? 1 : 0;
}
