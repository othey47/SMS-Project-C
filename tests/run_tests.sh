#!/bin/bash

# Student Management System Test Runner
# This script compiles and runs all test suites

echo "=========================================="
echo "Student Management System Test Runner"
echo "=========================================="

# Change to tests directory
cd "$(dirname "$0")"

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Function to print colored output
print_status() {
    if [ $1 -eq 0 ]; then
        echo -e "${GREEN}✓ $2${NC}"
    else
        echo -e "${RED}✗ $2${NC}"
    fi
}

# Clean previous builds
echo "Cleaning previous builds..."
make clean > /dev/null 2>&1

# Build comprehensive test suite
echo "Building comprehensive test suite..."
make test_comprehensive
if [ $? -eq 0 ]; then
    print_status 0 "Comprehensive test suite compiled successfully"
else
    print_status 1 "Failed to compile comprehensive test suite"
    exit 1
fi

# Build original test
echo "Building original test..."
make test_students
if [ $? -eq 0 ]; then
    print_status 0 "Original test compiled successfully"
else
    print_status 1 "Failed to compile original test"
    exit 1
fi

echo ""
echo "=========================================="
echo "Running Tests"
echo "=========================================="

# Run comprehensive tests
echo -e "${YELLOW}Running Comprehensive Test Suite...${NC}"
echo "----------------------------------------"
./test_comprehensive
COMPREHENSIVE_RESULT=$?

echo ""
echo "----------------------------------------"

# Run original tests
echo -e "${YELLOW}Running Original Test...${NC}"
echo "----------------------------------------"
./test_students
ORIGINAL_RESULT=$?

echo ""
echo "=========================================="
echo "Test Results Summary"
echo "=========================================="

if [ $COMPREHENSIVE_RESULT -eq 0 ]; then
    print_status 0 "Comprehensive test suite passed"
else
    print_status 1 "Comprehensive test suite failed"
fi

if [ $ORIGINAL_RESULT -eq 0 ]; then
    print_status 0 "Original test passed"
else
    print_status 1 "Original test failed"
fi

# Overall result
if [ $COMPREHENSIVE_RESULT -eq 0 ] && [ $ORIGINAL_RESULT -eq 0 ]; then
    echo -e "${GREEN}All tests passed! 🎉${NC}"
    exit 0
else
    echo -e "${RED}Some tests failed! ❌${NC}"
    exit 1
fi

