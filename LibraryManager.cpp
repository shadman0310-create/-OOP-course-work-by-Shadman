#include "LibraryManager.h"
#include <iostream>
#include <algorithm>
#include <stdexcept>

bool LibraryManager::isbnExists(const std::string& isbn) const {
    auto it = std::find_if(books.begin(), books.end(),
        [&isbn](const std::shared_ptr<Book>& b) {
            return b->getIsbn() == isbn;
        });
    return it != books.end();
}

void LibraryManager::addBook(std::shared_ptr<Book> book) {
    if (isbnExists(book->getIsbn())) {
        throw std::runtime_error("A book with ISBN '" + book->getIsbn() + "' already exists.");
    }
    books.push_back(std::move(book));
    std::cout << "Book added successfully.\n";
}

void LibraryManager::removeBook(const std::string& isbn) {
    auto it = std::find_if(books.begin(), books.end(),
        [&isbn](const std::shared_ptr<Book>& b) {
            return b->getIsbn() == isbn;
        });

    if (it == books.end()) {
        throw std::runtime_error("No book found with ISBN '" + isbn + "'.");
    }
    books.erase(it);
    std::cout << "Book removed successfully.\n";
}

void LibraryManager::searchByTitle(const std::string& query) const {
    bool found = false;
    for (const auto& b : books) {
        if (b->getTitle().find(query) != std::string::npos) {
            b->display();
            std::cout << "\n";
            found = true;
        }
    }
    if (!found) {
        std::cout << "No books found matching title: \"" << query << "\"\n";
    }
}

void LibraryManager::searchByAuthor(const std::string& query) const {
    bool found = false;
    for (const auto& b : books) {
        if (b->getAuthor().find(query) != std::string::npos) {
            b->display();
            std::cout << "\n";
            found = true;
        }
    }
    if (!found) {
        std::cout << "No books found matching author: \"" << query << "\"\n";
    }
}

void LibraryManager::displayAll() const {
    if (books.empty()) {
        std::cout << "The library is empty.\n";
        return;
    }
    for (const auto& b : books) {
        b->display();
        std::cout << "\n";
    }
}

void LibraryManager::sortByTitle() {
    std::sort(books.begin(), books.end(),
        [](const std::shared_ptr<Book>& a, const std::shared_ptr<Book>& b) {
            return a->getTitle() < b->getTitle();
        });
    std::cout << "Books sorted by title.\n";
}

void LibraryManager::sortByYear() {
    std::sort(books.begin(), books.end(),
        [](const std::shared_ptr<Book>& a, const std::shared_ptr<Book>& b) {
            return a->getYear() < b->getYear();
        });
    std::cout << "Books sorted by year.\n";
}

void LibraryManager::showSummary() const {
    int printed = 0, ebooks = 0, audio = 0;
    for (const auto& b : books) {
        if (b->getType() == "PrintedBook") ++printed;
        else if (b->getType() == "EBook") ++ebooks;
        else if (b->getType() == "AudioBook") ++audio;
    }
    std::cout << "=== Library Summary ===\n"
              << "  Total books  : " << books.size() << "\n"
              << "  Printed      : " << printed << "\n"
              << "  E-Books      : " << ebooks << "\n"
              << "  Audio Books  : " << audio << "\n";
}
