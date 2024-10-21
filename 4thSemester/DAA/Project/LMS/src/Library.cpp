#include "../includes/Library.h"
#include <iostream>
#include <algorithm>

Library::Library(const std::string& booksFile, const std::string& membersFile)
    : booksFilename(booksFile), membersFilename(membersFile) {
    books = FileStorage::loadBooks(booksFile);
    auto loadedMembers = FileStorage::loadMembers(membersFile);
    for (const auto& member : loadedMembers) {
        members[member.getID()] = member;
    }
}


void Library::addBook(const Book& book) {
    books.push_back(book);
    std::cout << "Book added successfully." << std::endl;
    saveData();
}

void Library::addMember(const Member& member) {
    members[member.getID()] = member;
    std::cout << "Member added successfully." << std::endl;
    saveData();
}

void Library::borrowBook(int memberId, int bookId) {
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

void Library::returnBook(int memberId, int bookId) {
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

void Library::searchBook(const std::string& searchTerm) const {
    bool found = false;
    for (const auto& book : books) {
        if (book.matches(searchTerm)) {
            book.displayDetails();
            found = true;
        }
    }
    if (!found) {
        std::cout << "No books found matching the search term." << std::endl;
    }
}

void Library::reserveBook(int memberId, int bookId) {
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

void Library::saveData() {
    FileStorage::saveBooks(booksFilename, books);
    FileStorage::saveMembers(membersFilename, std::vector<Member>(members.begin(), members.end()));
}
