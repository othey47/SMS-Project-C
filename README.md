# Student Management System

A robust console-based Student Management System implemented in C, featuring complete CRUD operations with persistent binary file storage. Perfect for learning C programming concepts including file I/O, data structures, and modular design patterns.


<div align="center">

**Database:** Files | **Language:** C | **Status:** Not Complete

</div>


## 🚀 Quick Start

```bash
# Clone and build
git clone https://github.com/yourusername/student-management-system-c.git
cd student-management-system-c
make

# Run the application
./student_manager
```

## ✨ Features

### Core Functionality

- **📝 Student Records**: Manage student ID, name, age, grade, and email
- **➕ Add Students**: Create new student entries with validation
- **📋 List All**: Display complete student database
- **🔍 Search**: Find students by unique ID
- **✏️ Update**: Modify existing student information
- **🗑️ Delete**: Remove student records safely

## 🛠️ Installation

### Method 1: Using Make (Recommended)

```bash
git clone https://github.com/yourusername/student-management-system-c.git
cd student-management-system-c
make
```

### Method 2: Manual Compilation

```bash
gcc -Wall -Wextra -std=c99 -o student_manager src/main.c src/student.c src/utils.c -I include
```
## 🎯 Usage

### Interactive Menu System

```
=== Student Management System ===
1. Add Student
2. List Students  
3. Search Student
4. Update Student
5. Delete Student
6. Exit
Enter your choice: _
```

### Example Workflow

```bash
# Add a new student
Choice: 1
Enter student name: Alice Johnson
Enter age: 21
Enter grade: 3.75
Enter email: alice@university.edu
✅ Student added successfully! (ID: 1001)

# List all students
Choice: 2
┌─────┬──────────────┬─────┬───────┬─────────────────────┐
│ ID  │ Name         │ Age │ Grade │ Email               │
├─────┼──────────────┼─────┼───────┼─────────────────────┤
│1001 │ Alice Johnson│ 21  │ 3.75  │ alice@university.edu│
└─────┴──────────────┴─────┴───────┴─────────────────────┘

# Search for specific student
Choice: 3
Enter student ID: 1001
🔍 Found: Alice Johnson (Age: 21, Grade: 3.75)
```

## 📁 Project Structure

```
student-management-system-c/
├── 📂 src/                     # Source code
│   ├── 📄 main.c               # Application entry point & UI
│   ├── 📄 student.c            # CRUD operations implementation  
│   └── 📄 utils.c              # Helper functions & validation
├── 📂 include/                 # Header files
│   ├── 📄 student.h            # Student struct & function declarations
│   └── 📄 utils.h              # Utility function prototypes
├── 📂 data/                    # Data storage (auto-created)
│   └── 📄 students.dat         # Binary database file
├── 📂 tests/                   # Unit tests
│   └── 📄 test_students.c      # Test suite
├── 📂 docs/                    # Documentation
│   └── 📄 design.md            # System architecture
├── 📄 Makefile                 # Build configuration
├── 📄 .gitignore              # Git ignore rules
├── 📄 README.md               # This file
└── 📄 LICENSE                 # MIT License
```

## 🏗️ Data Model

```c
typedef struct {
    int id;           // Unique identifier (auto-generated)
    char name[50];    // Student full name
    int age;          // Student age (1-150)
    float grade;      // GPA (0.0-4.0)
    char email[50];   // Email address
} Student;
```

### Field Specifications

- **ID**: Auto-generated unique integer starting from 1001
- **Name**: 1-49 characters, alphabetic + spaces only
- **Age**: Integer between 1 and 150
- **Grade**: Float between 0.0 and 4.0 (GPA scale)
- **Email**: Basic format validation (contains @ and .)

## 🧪 Testing

### Run Unit Tests

```bash
# Compile and run tests
gcc -o tests/test_students tests/test_students.c src/student.c src/utils.c -I include
./tests/test_students
```

### Manual Testing Scenarios

- ✅ Empty database operations
- ✅ Invalid input handling (strings in numeric fields)
- ✅ Boundary value testing (max string lengths)
- ✅ File corruption recovery
- ✅ Memory leak detection with Valgrind

### Debug Mode

```bash
# Compile with debug symbols
make debug

# Run with debugger
gdb ./student_manager
```

## 🔧 Configuration

### Makefile Targets

```bash
make              # Build release version
make debug        # Build with debug symbols
make clean        # Remove compiled files
make test         # Run unit tests
make install      # Install to system (optional)
```

### Customization

Edit `include/student.h` to modify:

- Maximum string lengths
- Grade scale ranges
- Default data file location

## 🚦 Error Handling

The system handles various error conditions gracefully:

- **File I/O Errors**: Automatic data directory creation
- **Invalid Input**: User-friendly error messages with retry prompts
- **Memory Issues**: Proper cleanup and error reporting
- **Data Corruption**: Backup and recovery suggestions

## 🛣️ Roadmap

### Current Version (v1.0)

- [x] Basic CRUD operations
- [x] Binary file storage
- [x] Input validation
- [x] Error handling

### Planned Features (v2.0)

- [ ] Data import/export (CSV, JSON)
- [ ] Advanced search filters
- [ ] Sorting capabilities
- [ ] Student photo support
- [ ] Backup/restore functionality

### Future Considerations (v3.0+)

- [ ] GUI interface (GTK/Qt)
- [ ] SQLite database backend
- [ ] Multi-user support
- [ ] Web interface
- [ ] Network synchronization

## 🤝 Contributing

We welcome contributions! Please follow these steps:

1. **Fork** the repository
2. **Create** a feature branch: `git checkout -b feature/amazing-feature`
3. **Commit** your changes: `git commit -m 'Add amazing feature'`
4. **Test** your changes thoroughly
5. **Push** to the branch: `git push origin feature/amazing-feature`
6. **Open** a Pull Request

### Contribution Guidelines

- Follow existing code style and formatting
- Add unit tests for new features
- Update documentation as needed
- Ensure all tests pass before submitting

## 📝 License
This project is licensed under the MIT License - see the LICENSE file for details.


## 🙏 Acknowledgments

- **Educational Purpose**: Designed for C programming education
- **Community**: Thanks to all contributors and users
- **Inspiration**: Classic console-based database applications

---

<div align="center"> <p>Made with ❤️ for learning C programming</p> <p>⭐ Star this repo if it helped you!</p> </div>
