#pragma once
#include "Book.h"

class EBook : public Book {
private:
    double fileSizeMB;
    std::string format;

public:
    EBook(const std::string& title, const std::string& author, int year,
          const std::string& isbn, double fileSizeMB, const std::string& format);

    void display() const override;
    std::string getType() const override;

    double getFileSizeMB() const;
    const std::string& getFormat() const;
};
