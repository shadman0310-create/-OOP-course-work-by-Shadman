#pragma once
#include "Book.h"

class PrintedBook : public Book {
private:
    int pageCount;
    std::string publisher;

public:
    PrintedBook(const std::string& title, const std::string& author, int year,
                const std::string& isbn, int pageCount, const std::string& publisher);

    void display() const override;
    std::string getType() const override;

    int getPageCount() const;
    const std::string& getPublisher() const;
};
