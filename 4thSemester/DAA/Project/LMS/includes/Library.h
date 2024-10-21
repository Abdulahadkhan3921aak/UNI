#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include "Member.h"
#include "FileStorage.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>


class Library
{
private:
    std::vector<Book> books;
    std::unordered_map<int, Member> members;
    std::string booksFilename;
    std::string membersFilename;

public:
    Library(const std::string &booksFile, const std::string &membersFile);
    void addBook(const Book &book);
    void addMember(const Member &member);
    void borrowBook(int memberId, int bookId);
    void returnBook(int memberId, int bookId);
    void searchBook(const std::string &searchTerm) const;
    void reserveBook(int memberId, int bookId);
    void saveData();
};

#endif // LIBRARY_H
