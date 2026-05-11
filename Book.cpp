#include "Book.h"
#include <stdexcept>

Book::Book(const std::string& title, const std::string& author, int year, const std::string& isbn)
    : title(title), author(author), year(year), isbn(isbn)
{
    if (title.empty()) {
        throw std::invalid_argument("Title cannot be empty.");
    }
    if (author.empty()) {
        throw std::invalid_argument("Author cannot be empty.");
    }
    if (year < 1000 || year > 2100) {
        throw std::invalid_argument("Year must be between 1000 and 2100.");
    }
}

const std::string& Book::getTitle() const { return title; }
const std::string& Book::getAuthor() const { return author; }
int Book::getYear() const { return year; }
const std::string& Book::getIsbn() const { return isbn; }
