
#include "../include/Member.h"
#include <iostream>

Member::Member() {}

void Member::inputDetails() {
    std::cout << "Enter Member ID: ";
    std::cin >> id;
    std::cin.ignore();
    std::cout << "Enter Name: ";
    std::getline(std::cin, name);
    std::cout << "Enter Contact Details: ";
    std::getline(std::cin, contactDetails);
}

int Member::getID() const {
    return id;
}

void Member::displayDetails() const {
    std::cout << "Member ID: " << id << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Contact Details: " << contactDetails << std::endl;
}

void Member::borrowBook(int bookId) {
    borrowingHistory.push_back(bookId);
}

void Member::returnBook(int bookId) {
    auto it = std::find(borrowingHistory.begin(), borrowingHistory.end(), bookId);
    if (it != borrowingHistory.end()) {
        borrowingHistory.erase(it);
    }
}

void Member::reserveBook(int bookId) {
    reservedBooks.push_back(bookId);
}