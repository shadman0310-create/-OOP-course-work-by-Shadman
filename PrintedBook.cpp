#include "PrintedBook.h"
#include <iostream>
#include <stdexcept>

PrintedBook::PrintedBook(const std::string& title, const std::string& author, int year,
                         const std::string& isbn, int pageCount, const std::string& publisher)
    : Book(title, author, year, isbn), pageCount(pageCount), publisher(publisher)
{
    if (pageCount <= 0) {
        throw std::invalid_argument("Page count must be positive.");
    }
}

void PrintedBook::display() const {
    std::cout << "[Printed Book]\n"
              << "  Title     : " << title << "\n"
              << "  Author    : " << author << "\n"
              << "  Year      : " << year << "\n"
              << "  ISBN      : " << isbn << "\n"
              << "  Pages     : " << pageCount << "\n"
              << "  Publisher : " << publisher << "\n";
}

std::string PrintedBook::getType() const { return "PrintedBook"; }
int PrintedBook::getPageCount() const { return pageCount; }
const std::string& PrintedBook::getPublisher() const { return publisher; }
