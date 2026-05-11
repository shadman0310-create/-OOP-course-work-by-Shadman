#pragma once
#include "Book.h"
#include <vector>
#include <memory>
#include <string>

class LibraryManager {
private:
    std::vector<std::shared_ptr<Book>> books;

    bool isbnExists(const std::string& isbn) const;

public:
    void addBook(std::shared_ptr<Book> book);
    void removeBook(const std::string& isbn);

    void searchByTitle(const std::string& query) const;
    void searchByAuthor(const std::string& query) const;

    void displayAll() const;
    void sortByTitle();
    void sortByYear();
    void showSummary() const;

    template<typename T>
    std::vector<std::shared_ptr<T>> filterBooks() const {
        std::vector<std::shared_ptr<T>> result;
        for (const auto& b : books) {
            auto casted = std::dynamic_pointer_cast<T>(b);
            if (casted) {
                result.push_back(casted);
            }
        }
        return result;
    }
};
