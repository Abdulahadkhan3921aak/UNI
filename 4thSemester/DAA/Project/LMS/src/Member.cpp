#include "../includes/Member.h"
#include <iostream>

Member::Member()
{
    id = 0;
    name = "";
    contactDetails = "";
}
void Member::inputDetails()
{
    std::cout << "Enter Member ID: ";
    std::cin >> id;
    std::cin.ignore();
    std::cout << "Enter Name: ";
    std::getline(std::cin, name);
    std::cout << "Enter Contact Details: ";
    std::getline(std::cin, contactDetails);
}

void Member::displayDetails() const
{
    std::cout << "Member ID: " << id << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Contact Details: " << contactDetails << std::endl;
}

void Member::borrowBook(int bookId)
{
    borrowingHistory.push_back(bookId);
}

void Member::returnBook(int bookId)
{
    auto it = std::find(borrowingHistory.begin(), borrowingHistory.end(), bookId);
    if (it != borrowingHistory.end())
    {
        borrowingHistory.erase(it);
    }
}

void Member::reserveBook(int bookId)
{
    reservedBooks.push_back(bookId);
}

int Member::getID() const
{
    return id;
}
std::string Member::getName() const
{
    return name;
}
std::string Member::getContactDetails() const
{
    return contactDetails;
}

std::string Member::getBorrowingHistoryString() const
{
    std::string historyString;
    for (int bookId : borrowingHistory)
    {
        historyString += std::to_string(bookId) + ",";
    }
    // Remove the trailing comma, if any
    if (!historyString.empty())
    {
        historyString.pop_back();
    }
    return historyString;
}

std::string Member::getReservedBooksString() const
{
    std::string reservedString;
    for (int bookId : reservedBooks)
    {
        reservedString += std::to_string(bookId) + ",";
    }
    // Remove the trailing comma, if any
    if (!reservedString.empty())
    {
        reservedString.pop_back();
    }
    return reservedString;
}

void Member::setID(int id)
{
    this->id = id;
}
void Member::setName(std::string name)
{
    this->name = name;
}
void Member::setContactDetails(std::string contactDetails)
{
    this->contactDetails = contactDetails;
}
