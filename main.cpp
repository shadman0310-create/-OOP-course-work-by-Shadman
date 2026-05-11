#include <iostream>
#include <string>
#include <limits>
#include <memory>

#include "LibraryManager.h"
#include "PrintedBook.h"
#include "EBook.h"
#include "AudioBook.h"

static void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

static std::string readLine(const std::string& prompt) {
    std::string value;
    std::cout << prompt;
    std::getline(std::cin, value);
    return value;
}

static int readInt(const std::string& prompt) {
    int value;
    std::cout << prompt;
    while (!(std::cin >> value)) {
        clearInput();
        std::cout << "Invalid input. " << prompt;
    }
    clearInput();
    return value;
}

static double readDouble(const std::string& prompt) {
    double value;
    std::cout << prompt;
    while (!(std::cin >> value)) {
        clearInput();
        std::cout << "Invalid input. " << prompt;
    }
    clearInput();
    return value;
}

static void addPrintedBook(LibraryManager& manager) {
    std::string title  = readLine("Title     : ");
    std::string author = readLine("Author    : ");
    int year           = readInt ("Year      : ");
    std::string isbn   = readLine("ISBN      : ");
    int pages          = readInt ("Pages     : ");
    std::string pub    = readLine("Publisher : ");

    auto book = std::make_shared<PrintedBook>(title, author, year, isbn, pages, pub);
    manager.addBook(std::move(book));
}

static void addEBook(LibraryManager& manager) {
    std::string title  = readLine("Title      : ");
    std::string author = readLine("Author     : ");
    int year           = readInt ("Year       : ");
    std::string isbn   = readLine("ISBN       : ");
    double size        = readDouble("Size (MB) : ");
    std::string format = readLine("Format     : ");

    auto book = std::make_shared<EBook>(title, author, year, isbn, size, format);
    manager.addBook(std::move(book));
}

static void addAudioBook(LibraryManager& manager) {
    std::string title    = readLine("Title        : ");
    std::string author   = readLine("Author       : ");
    int year             = readInt ("Year         : ");
    std::string isbn     = readLine("ISBN         : ");
    double duration      = readDouble("Duration (min): ");
    std::string narrator = readLine("Narrator     : ");

    auto book = std::make_shared<AudioBook>(title, author, year, isbn, duration, narrator);
    manager.addBook(std::move(book));
}

static void menuAdd(LibraryManager& manager) {
    std::cout << "\n--- Add Book ---\n"
              << "  1. Printed Book\n"
              << "  2. E-Book\n"
              << "  3. Audio Book\n"
              << "Choice: ";
    int choice = readInt("");
    try {
        if (choice == 1) addPrintedBook(manager);
        else if (choice == 2) addEBook(manager);
        else if (choice == 3) addAudioBook(manager);
        else std::cout << "Invalid choice.\n";
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
    }
}

static void menuRemove(LibraryManager& manager) {
    std::string isbn = readLine("\nEnter ISBN to remove: ");
    try {
        manager.removeBook(isbn);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
    }
}

static void menuSearch(LibraryManager& manager) {
    std::cout << "\n--- Search ---\n"
              << "  1. By title\n"
              << "  2. By author\n"
              << "Choice: ";
    int choice = readInt("");
    if (choice == 1) {
        std::string query = readLine("Title keyword: ");
        manager.searchByTitle(query);
    } else if (choice == 2) {
        std::string query = readLine("Author keyword: ");
        manager.searchByAuthor(query);
    } else {
        std::cout << "Invalid choice.\n";
    }
}

static void menuSort(LibraryManager& manager) {
    std::cout << "\n--- Sort ---\n"
              << "  1. By title\n"
              << "  2. By year\n"
              << "Choice: ";
    int choice = readInt("");
    if (choice == 1) manager.sortByTitle();
    else if (choice == 2) manager.sortByYear();
    else std::cout << "Invalid choice.\n";
}

static void menuFilter(LibraryManager& manager) {
    std::cout << "\n--- Filter by Type ---\n"
              << "  1. Printed Books\n"
              << "  2. E-Books\n"
              << "  3. Audio Books\n"
              << "Choice: ";
    int choice = readInt("");
    if (choice == 1) {
        auto results = manager.filterBooks<PrintedBook>();
        if (results.empty()) { std::cout << "No printed books found.\n"; return; }
        for (const auto& b : results) { b->display(); std::cout << "\n"; }
    } else if (choice == 2) {
        auto results = manager.filterBooks<EBook>();
        if (results.empty()) { std::cout << "No e-books found.\n"; return; }
        for (const auto& b : results) { b->display(); std::cout << "\n"; }
    } else if (choice == 3) {
        auto results = manager.filterBooks<AudioBook>();
        if (results.empty()) { std::cout << "No audio books found.\n"; return; }
        for (const auto& b : results) { b->display(); std::cout << "\n"; }
    } else {
        std::cout << "Invalid choice.\n";
    }
}

static void printMenu() {
    std::cout << "\n============================\n"
              << "   Console Library System\n"
              << "============================\n"
              << "  1. Add a book\n"
              << "  2. Remove a book\n"
              << "  3. Search books\n"
              << "  4. Display all books\n"
              << "  5. Sort books\n"
              << "  6. Show summary\n"
              << "  7. Filter by type\n"
              << "  0. Exit\n"
              << "============================\n"
              << "Choice: ";
}

int main() {
    LibraryManager manager;

    try {
        manager.addBook(std::make_shared<PrintedBook>(
            "The C++ Programming Language", "Bjarne Stroustrup", 2013, "978-0321563842", 1376, "Addison-Wesley"));
        manager.addBook(std::make_shared<EBook>(
            "Clean Code", "Robert C. Martin", 2008, "978-0132350884", 3.5, "PDF"));
        manager.addBook(std::make_shared<AudioBook>(
            "Effective Modern C++", "Scott Meyers", 2014, "978-1491903995", 480.0, "John Smith"));
    } catch (const std::exception& e) {
        std::cout << "Startup error: " << e.what() << "\n";
    }

    int choice = -1;
    while (choice != 0) {
        printMenu();
        choice = readInt("");
        switch (choice) {
            case 1: menuAdd(manager);    break;
            case 2: menuRemove(manager); break;
            case 3: menuSearch(manager); break;
            case 4: manager.displayAll(); break;
            case 5: menuSort(manager);   break;
            case 6: manager.showSummary(); break;
            case 7: menuFilter(manager); break;
            case 0: std::cout << "Goodbye!\n"; break;
            default: std::cout << "Invalid option. Try again.\n";
        }
    }

    return 0;
}
