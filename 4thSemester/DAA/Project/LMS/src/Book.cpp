#include "../includes/Book.h"
#include <iostream>

Book::Book() : isAvailable(true) {}

void Book::inputDetails()
{
    std::cout << "Enter Book ID: ";
    std::cin >> id;
    std::cin.ignore();
    std::cout << "Enter Title: ";
    std::getline(std::cin, title);
    std::cout << "Enter Author: ";
    std::getline(std::cin, author);
    std::cout << "Enter ISBN: ";
    std::getline(std::cin, ISBN);
    std::cout << "Enter Category: ";
    std::getline(std::cin, category);
}

int Book::getId() const
{
    return id;
}

bool Book::checkAvailability() const
{
    return isAvailable;
}

void Book::setAvailability(bool status)
{
    isAvailable = status;
}

void Book::displayDetails() const
{
    std::cout << "Book ID: " << id << std::endl;
    std::cout << "Title: " << title << std::endl;
    std::cout << "Author: " << author << std::endl;
    std::cout << "ISBN: " << ISBN << std::endl;
    std::cout << "Category: " << category << std::endl;
    std::cout << "Availability: " << (isAvailable ? "Available" : "Not Available") << std::endl;
}

bool Book::matches(const std::string &searchTerm) const
{
    return title.find(searchTerm) != std::string::npos ||
           author.find(searchTerm) != std::string::npos ||
           ISBN.find(searchTerm) != std::string::npos ||
           category.find(searchTerm) != std::string::npos;
}

std::string Book::getTitle() const
{
    return this->title;
}

std::string Book::getAuthor() const
{
    return this->author;
}

std::string Book::getISBN() const
{
    return this->ISBN;
}

std::string Book::getCategory() const
{
    return this->category;
}


void Book::setId(int id){
    id = id;
}
void Book::setTitle(std::string title){
    title = title;
}
void Book::setAuthor(std::string author){
    author = author;
}
void Book::setISBN(std::string ISBN){
    ISBN = ISBN;
}
void Book::setCategory(std::string category){
    category = category;
}
