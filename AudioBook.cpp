#include "AudioBook.h"
#include <iostream>
#include <stdexcept>

AudioBook::AudioBook(const std::string& title, const std::string& author, int year,
                     const std::string& isbn, double durationMinutes, const std::string& narrator)
    : Book(title, author, year, isbn), durationMinutes(durationMinutes), narrator(narrator)
{
    if (durationMinutes <= 0.0) {
        throw std::invalid_argument("Duration must be positive.");
    }
    if (narrator.empty()) {
        throw std::invalid_argument("Narrator cannot be empty.");
    }
}

void AudioBook::display() const {
    std::cout << "[Audio Book]\n"
              << "  Title    : " << title << "\n"
              << "  Author   : " << author << "\n"
              << "  Year     : " << year << "\n"
              << "  ISBN     : " << isbn << "\n"
              << "  Duration : " << durationMinutes << " min\n"
              << "  Narrator : " << narrator << "\n";
}

std::string AudioBook::getType() const { return "AudioBook"; }
double AudioBook::getDurationMinutes() const { return durationMinutes; }
const std::string& AudioBook::getNarrator() const { return narrator; }
