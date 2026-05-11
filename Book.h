#pragma once
#include <string>

class Book {
protected:
    std::string title;
    std::string author;
    int year;
    std::string isbn;

public:
    Book(const std::string& title, const std::string& author, int year, const std::string& isbn);
    virtual ~Book() = default;

    virtual void display() const = 0;
    virtual std::string getType() const = 0;

    const std::string& getTitle() const;
    const std::string& getAuthor() const;
    int getYear() const;
    const std::string& getIsbn() const;
};
