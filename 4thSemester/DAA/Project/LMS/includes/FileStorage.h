#ifndef FILE_STORAGE_H
#define FILE_STORAGE_H

#include <string>
#include <vector>
#include "../includes/Book.h"
#include "../includes/Member.h"



class FileStorage {
public:
    static void saveBooks(const std::string& filename, const std::vector<Book>& books);
    static void saveMembers(const std::string& filename, const std::vector<Member>& members);
    static std::vector<Book> loadBooks(const std::string& filename);
    static std::vector<Member> loadMembers(const std::string& filename);
};

#endif // FILE_STORAGE_H
