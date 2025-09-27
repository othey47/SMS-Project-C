# Testing Guide

This directory contains unit tests for the Student Management System (SMS) project.

## 🧪 Test Structure

The testing framework is designed to validate all core functionality of the SMS system including:
- Student CRUD operations (Create, Read, Update, Delete)
- Data validation and input handling
- File I/O operations
- Error handling and edge cases

## 🚀 Running Tests

### Quick Start

```bash
# From the project root directory
make test
```

This command will:
1. Compile the test suite with all necessary source files
2. Execute all unit tests
3. Display test results

### Manual Test Compilation

If you prefer to compile tests manually:

```bash
# Compile test suite
gcc -Wall -Wextra -std=c11 -I../include test_students.c ../src/student.c ../src/utils.c -o run_tests

# Run tests
./run_tests
```

### Using Makefile Targets

The project includes several testing-related make targets:

```bash
# Run all tests
make test

# Clean test artifacts
make clean

# Build and run tests in one command
make test && ./tests/run_tests
```

## 📋 Test Categories

### 1. Student Management Tests
- **Add Student**: Validates student creation with proper data
- **List Students**: Tests student retrieval and display
- **Search Student**: Validates student lookup by ID
- **Update Student**: Tests student information modification
- **Delete Student**: Validates student removal

### 2. Data Validation Tests
- **Input Validation**: Tests invalid input handling
- **Boundary Testing**: Validates min/max values for fields
- **Format Validation**: Tests email and name format validation
- **Edge Cases**: Tests empty inputs and special characters

### 3. File Operations Tests
- **File Creation**: Tests data file initialization
- **Data Persistence**: Validates save/load operations
- **File Corruption**: Tests error handling for corrupted files
- **Empty File**: Tests behavior with empty data files

### 4. Error Handling Tests
- **Memory Management**: Tests for memory leaks
- **File I/O Errors**: Tests file permission and access issues
- **Invalid Operations**: Tests operations on non-existent data
- **System Resource Tests**: Tests behavior under resource constraints

## 🔧 Test Configuration

### Compiler Flags
Tests are compiled with the following flags for maximum safety:
- `-Wall`: Enable all warnings
- `-Wextra`: Enable extra warnings
- `-std=c11`: Use C11 standard
- `-I../include`: Include header files

### Test Data
- Tests use isolated data files to avoid conflicts
- Each test cleans up after itself
- Test data is stored in `tests/test_data/` directory

## 📊 Expected Test Output

```
=== Student Management System - Test Suite ===

Running Student Management Tests...
✓ Add Student Test: PASSED
✓ List Students Test: PASSED
✓ Search Student Test: PASSED
✓ Update Student Test: PASSED
✓ Delete Student Test: PASSED

Running Data Validation Tests...
✓ Input Validation Test: PASSED
✓ Boundary Testing: PASSED
✓ Format Validation: PASSED
✓ Edge Cases: PASSED

Running File Operations Tests...
✓ File Creation: PASSED
✓ Data Persistence: PASSED
✓ File Corruption: PASSED
✓ Empty File: PASSED

Running Error Handling Tests...
✓ Memory Management: PASSED
✓ File I/O Errors: PASSED
✓ Invalid Operations: PASSED
✓ System Resource Tests: PASSED

=== Test Results ===
Total Tests: 16
Passed: 16
Failed: 0
Success Rate: 100%
```

## 🐛 Debugging Tests

### Running Individual Tests
To run specific test categories, you can modify the test file or use debug flags:

```bash
# Compile with debug symbols
gcc -g -Wall -Wextra -std=c11 -I../include test_students.c ../src/student.c ../src/utils.c -o run_tests_debug

# Run with debugger
gdb ./run_tests_debug
```

### Memory Leak Detection
Use Valgrind to detect memory leaks:

```bash
# Install valgrind (if not already installed)
sudo apt-get install valgrind

# Run tests with memory checking
valgrind --leak-check=full --show-leak-kinds=all ./tests/run_tests
```

### Test Coverage
To analyze test coverage:

```bash
# Compile with coverage flags
gcc -fprofile-arcs -ftest-coverage -Wall -Wextra -std=c11 -I../include test_students.c ../src/student.c ../src/utils.c -o run_tests_coverage

# Run tests
./run_tests_coverage

# Generate coverage report
gcov test_students.c
```

## 📝 Writing New Tests

When adding new tests to `test_students.c`:

1. **Follow Naming Convention**: Use descriptive test names
2. **Test Isolation**: Each test should be independent
3. **Cleanup**: Always clean up test data after each test
4. **Assertions**: Use clear assertion messages
5. **Documentation**: Add comments explaining test purpose

### Example Test Structure:
```c
void test_add_student() {
    printf("Testing student addition...\n");
    
    // Setup
    initStudentSys();
    
    // Test
    Student new_student = {1001, "John Doe", 20, 3.5, "john@example.com"};
    int result = addStudent(new_student);
    
    // Assert
    if (result == 0) {
        printf("✓ Add Student Test: PASSED\n");
    } else {
        printf("✗ Add Student Test: FAILED\n");
    }
    
    // Cleanup
    cleanupStudentSys();
}
```

## 🚨 Troubleshooting

### Common Issues

1. **Compilation Errors**:
   - Ensure all source files are present
   - Check include paths are correct
   - Verify C11 standard support

2. **Test Failures**:
   - Check file permissions for data directory
   - Ensure no other processes are using test files
   - Verify test data is properly initialized

3. **Memory Issues**:
   - Run with Valgrind to detect leaks
   - Check for proper cleanup in tests
   - Verify all allocated memory is freed

### Getting Help

If you encounter issues:
1. Check the main project README.md
2. Review the Makefile for build configuration
3. Ensure all dependencies are installed
4. Check file permissions in the project directory

---
## 📝 License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

**Note**: Always run tests from the project root directory to ensure proper file paths and dependencies are resolved.