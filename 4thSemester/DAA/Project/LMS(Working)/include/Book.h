
#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
private:
    int id;
    std::string title;
    std::string author;
    std::string ISBN;
    std::string category;
    bool isAvailable;

public:
    Book();
    void inputDetails();
    int getId() const;
    bool checkAvailability() const;
    void setAvailability(bool status);
    void displayDetails() const;
    bool matches(const std::string& searchTerm) const; // New method
};

#endif // BOOK_H
