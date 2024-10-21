#include "../includes/FileStorage.h"
#include <fstream>
#include <iostream>
#include <sstream>

void FileStorage::saveBooks(const std::string& filename, const std::vector<Book>& books) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }

    for (const auto& book : books) {
        file << book.getId() << ","
             << book.getTitle() << ","
             << book.getAuthor() << ","
             << book.getISBN() << ","
             << book.getCategory() << ","
             << (book.checkAvailability() ? "1" : "0") << "\n";
    }

    file.close();
}

void FileStorage::saveMembers(const std::string& filename, const std::vector<Member>& members) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }

    for (const auto& member : members) {
        file << member.getID() << ","
             << member.getName() << ","
             << member.getContactDetails() << ","
             << member.getBorrowingHistoryString() << ","
             << member.getReservedBooksString() << "\n";
    }

    file.close();
}

std::vector<Book> FileStorage::loadBooks(const std::string& filename) {
    std::vector<Book> books;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return books;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string id, title, author, isbn, category, availability;
        std::getline(ss, id, ',');
        std::getline(ss, title, ',');
        std::getline(ss, author, ',');
        std::getline(ss, isbn, ',');
        std::getline(ss, category, ',');
        std::getline(ss, availability, ',');

        Book book;
        book.setId(std::stoi(id));
        book.setTitle(title);
        book.setAuthor(author);
        book.setISBN(isbn);
        book.setCategory(category);
        book.setAvailability(availability == "1");
        books.push_back(book);
    }

    file.close();
    return books;
}

std::vector<Member> FileStorage::loadMembers(const std::string& filename) {
    std::vector<Member> members;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return members;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string id, name, contact, borrowingHistory, reservedBooks;
        std::getline(ss, id, ',');
        std::getline(ss, name, ',');
        std::getline(ss, contact, ',');
        std::getline(ss, borrowingHistory, ',');
        std::getline(ss, reservedBooks, ',');

        Member member;
        member.setID(std::stoi(id));
        member.setName(name);
        member.setContactDetails(contact);
        member.setBorrowingHistoryFromString(borrowingHistory);
        member.setReservedBooksFromString(reservedBooks);
        members.push_back(member);
    }

    file.close();
    return members;
}
