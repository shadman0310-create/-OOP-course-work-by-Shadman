#include "EBook.h"
#include <iostream>
#include <stdexcept>

EBook::EBook(const std::string& title, const std::string& author, int year,
             const std::string& isbn, double fileSizeMB, const std::string& format)
    : Book(title, author, year, isbn), fileSizeMB(fileSizeMB), format(format)
{
    if (fileSizeMB <= 0.0) {
        throw std::invalid_argument("File size must be positive.");
    }
    if (format.empty()) {
        throw std::invalid_argument("Format cannot be empty.");
    }
}

void EBook::display() const {
    std::cout << "[E-Book]\n"
              << "  Title    : " << title << "\n"
              << "  Author   : " << author << "\n"
              << "  Year     : " << year << "\n"
              << "  ISBN     : " << isbn << "\n"
              << "  Size     : " << fileSizeMB << " MB\n"
              << "  Format   : " << format << "\n";
}

std::string EBook::getType() const { return "EBook"; }
double EBook::getFileSizeMB() const { return fileSizeMB; }
const std::string& EBook::getFormat() const { return format; }
