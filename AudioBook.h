#pragma once
#include "Book.h"

class AudioBook : public Book {
private:
    double durationMinutes;
    std::string narrator;

public:
    AudioBook(const std::string& title, const std::string& author, int year,
              const std::string& isbn, double durationMinutes, const std::string& narrator);

    void display() const override;
    std::string getType() const override;

    double getDurationMinutes() const;
    const std::string& getNarrator() const;
};
