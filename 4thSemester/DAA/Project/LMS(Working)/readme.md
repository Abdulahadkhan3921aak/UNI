# Library Management System

## Overview

The Library Management System is a software application designed to manage the operations of a library, including adding and removing books, registering and updating member information, borrowing and returning books, searching for books, and reserving books. This project is implemented in C++.

## Features

- Add new books to the library database.
- Add new members to the library database.
- Borrow books from the library.
- Return books to the library.
- Search for books by title, author, ISBN, or category.
- Reserve books for future borrowing.

## Implementation Details

### Classes

- **Book**: Represents a book in the library. It contains attributes such as ID, title, author, ISBN, category, and availability status. Methods are provided to input details, get book information, check availability, and match search terms.
- **Member**: Represents a library member. It contains attributes such as ID, name, contact details, borrowing history, and reserved books. Methods are provided to input details, get member information, borrow books, return books, and reserve books.
- **Library**: Represents the library itself. It contains collections of books and members. Methods are provided to add books and members, borrow and return books, search for books, and reserve books.

### Data Structures

- **Vector**: Used to store collections of books and members in the Library class. Vectors provide dynamic arrays with the ability to resize, making them suitable for managing variable-sized collections.
- **Unordered Map**: Used to store member information in the Library class, with member IDs as keys and member objects as values. Unordered maps provide fast access to elements using keys, making them suitable for storing and retrieving data by unique identifiers.

### Hashing Function

- **Book ID Hashing Function**: Book IDs are used as keys in the unordered map storing member information. The hashing function for book IDs is implemented internally by the unordered map container, providing efficient storage and retrieval of member data based on book IDs.

## Usage

### Command Line Interface (CLI)

1. Compile the source files using the provided batch script `CommandLineInterface.bat`.
2. Run the executable `LMS(CLI)` to launch the command-line interface.
3. Follow the on-screen prompts to interact with the library management system.

### Menu-Driven Interface (MDI)

1. Compile the source files using the provided batch script `MenuDrivenInterface.bat`.
2. Run the executable `LMS(MDI)` to launch the menu-driven interface.
3. Use arrow keys to navigate the menu and press Enter to select options.
4. Follow the on-screen prompts to interact with the library management system.

## Contributors

- Abdul Ahad (22-CS-071)
- Mugammad Zain Ali (22-CS-015)
- Junaid Jiya Khan (22-CS-182)
- Muhammad Afzal (22-CS-071)

## License

This project is licensed under the [MIT License](LICENSE).
