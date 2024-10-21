
#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <unordered_map>
#include "Book.h"
#include "Member.h"

class Library {
private:
    std::vector<Book> books;
    std::unordered_map<int, Member> members;

public:
    void addBook();
    void addMember();
    void borrowBook();
    void returnBook();
    void searchBook();
    void reserveBook();
};

#endif // LIBRARY_H
