#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book
{
private:
    int id;
    std::string title;
    std::string author;
    std::string ISBN;
    std::string category;
    bool isAvailable;

public:
    Book();
    int getId() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getISBN() const;
    std::string getCategory() const;
    void setId(int id);
    void setTitle(std::string title);
    void setAuthor(std::string author);
    void setISBN(std::string ISBN); // New method (setISBN)
    void setCategory(std::string category);
    void inputDetails();
    bool checkAvailability() const;
    void setAvailability(bool status);
    void displayDetails() const;
    bool matches(const std::string &searchTerm) const; // New method
};

#endif // BOOK_H
