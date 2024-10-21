
#include "../include/Library.h"
#include <iostream>
#include <algorithm>

void Library::addBook() {
    Book newBook;
    newBook.inputDetails();
    books.push_back(newBook);
    std::cout << "Book added successfully." << std::endl;
}

void Library::addMember() {
    Member newMember;
    newMember.inputDetails();
    members[newMember.getID()] = newMember;
    std::cout << "Member added successfully." << std::endl;
}

void Library::borrowBook() {
    int memberId, bookId;
    std::cout << "Enter Member ID: ";
    std::cin >> memberId;
    std::cout << "Enter Book ID: ";
    std::cin >> bookId;

    auto memberIter = members.find(memberId);
    if (memberIter == members.end()) {
        std::cout << "Member not found." << std::endl;
        return;
    }

    auto bookIter = std::find_if(books.begin(), books.end(), [bookId](const Book& book) {
        return book.getId() == bookId;
    });

    if (bookIter == books.end()) {
        std::cout << "Book not found." << std::endl;
        return;
    }

    if (!bookIter->checkAvailability()) {
        std::cout << "Book is already borrowed." << std::endl;
        return;
    }

    bookIter->setAvailability(false);
    memberIter->second.borrowBook(bookId);
    std::cout << "Book borrowed successfully." << std::endl;
}

void Library::returnBook() {
    int memberId, bookId;
    std::cout << "Enter Member ID: ";
    std::cin >> memberId;
    std::cout << "Enter Book ID: ";
    std::cin >> bookId;

    auto memberIter = members.find(memberId);
    if (memberIter == members.end()) {
        std::cout << "Member not found." << std::endl;
        return;
    }

    auto bookIter = std::find_if(books.begin(), books.end(), [bookId](const Book& book) {
        return book.getId() == bookId;
    });

    if (bookIter == books.end()) {
        std::cout << "Book not found." << std::endl;
        return;
    }

    if (bookIter->checkAvailability()) {
        std::cout << "Book is not currently borrowed." << std::endl;
        return;
    }

    bookIter->setAvailability(true);
    memberIter->second.returnBook(bookId);
    std::cout << "Book returned successfully." << std::endl;
}

void Library::searchBook() {
    std::string searchTerm;
    std::cout << "Enter search term (title/author/ISBN/category): ";
    std::cin.ignore();
    std::getline(std::cin, searchTerm);

    for (const auto& book : books) {
        if (book.matches(searchTerm)) {
            book.displayDetails();
        }
    }
}

void Library::reserveBook() {
    int memberId, bookId;
    std::cout << "Enter Member ID: ";
    std::cin >> memberId;
    std::cout << "Enter Book ID: ";
    std::cin >> bookId;

    auto memberIter = members.find(memberId);
    if (memberIter == members.end()) {
        std::cout << "Member not found." << std::endl;
        return;
    }

    auto bookIter = std::find_if(books.begin(), books.end(), [bookId](const Book& book) {
        return book.getId() == bookId;
    });

    if (bookIter == books.end()) {
        std::cout << "Book not found." << std::endl;
        return;
    }

    if (bookIter->checkAvailability()) {
        std::cout << "Book is available, no need to reserve." << std::endl;
        return;
    }

    memberIter->second.reserveBook(bookId);
    std::cout << "Book reserved successfully." << std::endl;
}