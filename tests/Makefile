# Makefile for Student Management System Tests
# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
INCLUDES = -I../include
LDFLAGS = 

# Source directories
SRC_DIR = ../src
INCLUDE_DIR = ../include

# Test targets
TEST_TARGETS = test_comprehensive test_students

# Default target
all: $(TEST_TARGETS)

# Comprehensive test
test_comprehensive: test_comprehensive.c
	$(CC) $(CFLAGS) $(INCLUDES) -o test_comprehensive test_comprehensive.c $(SRC_DIR)/student.c $(SRC_DIR)/utils.c $(LDFLAGS)

# Original test
test_students: test_students.c
	$(CC) $(CFLAGS) $(INCLUDES) -o test_students test_students.c $(SRC_DIR)/student.c $(SRC_DIR)/utils.c $(LDFLAGS)

# Run comprehensive tests
run-comprehensive: test_comprehensive
	./test_comprehensive

# Run original tests
run-original: test_students
	./test_students

# Run all tests
run-all: run-comprehensive run-original

# Clean up
clean:
	rm -f $(TEST_TARGETS) *.o *.dat

# Help
help:
	@echo "Available targets:"
	@echo "  all              - Build all test programs"
	@echo "  test_comprehensive - Build comprehensive test suite"
	@echo "  test_students    - Build original test program"
	@echo "  run-comprehensive - Run comprehensive tests"
	@echo "  run-original     - Run original tests"
	@echo "  run-all          - Run all tests"
	@echo "  clean            - Remove all generated files"
	@echo "  help             - Show this help message"

.PHONY: all clean help run-comprehensive run-original run-all


