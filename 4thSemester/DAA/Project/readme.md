### Library Management System

This C++ program implements a simple library management system that allows users to manage books and members of a library. It provides functionalities such as adding and removing books, adding and removing members, borrowing and returning books, and displaying all books in the library.

#### Dependencies
- C++ Standard Library

#### How to Use
1. Compile the program using a C++ compiler.
2. Run the compiled executable.
3. Follow the menu prompts to perform various operations like adding books, removing books, adding members, removing members, borrowing books, returning books, and displaying all books in the library.
4. Enter `8` to exit the program.

#### Functionality
- **Add Book**: Allows users to add a new book to the library by entering its details such as title, author, ISBN, category, availability, and location.
- **Remove Book**: Allows users to remove a book from the library by entering its ISBN.
- **Add Member**: Allows users to add a new member to the library by entering their details such as name, contact details, and membership ID.
- **Remove Member**: Allows users to remove a member from the library by entering their membership ID.
- **Borrow Book**: Allows users to borrow a book from the library by entering its ISBN and the membership ID of the member.
- **Return Book**: Allows users to return a book to the library by entering its ISBN and the membership ID of the member.
- **Display All Books**: Displays all the books in the library, including their title, author, ISBN, category, availability, and location.
- **Exit**: Exits the program.

#### Structures
- **Book**: Represents a book in the library, containing information such as title, author, ISBN, category, availability, and location.
- **Member**: Represents a member of the library, containing information such as name, contact details, membership ID, and borrowing history.
- **ISBNHash**: Defines a custom hashing function for book ISBNs.
- **LibraryManagementSystem**: Implements the core functionality of the library management system, including operations for book and member management, borrowing and returning books, and displaying all books.

#### Usage
```bash
// Compile the program
g++ library_management_system.cpp -o library_management_system

// Run the compiled executable
./library_management_system
