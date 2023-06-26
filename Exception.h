//
// Created by omar_ on 21/06/2023.
//
#ifndef EX4_EXCEPTION_H
#define EX4_EXCEPTION_H
#include <stdexcept>
#include <exception>

class DeckFileNotFound : public std::runtime_error {
public:
    explicit DeckFileNotFound(const std::string& message)
            : std::runtime_error(message) {}
};

class DeckFileFormatError : public std::runtime_error{
public:
    explicit DeckFileFormatError(const std::string& message)
            : std::runtime_error(message) {}
};

class DeckFileInvalidSize : public std::runtime_error{
public:
    explicit DeckFileInvalidSize(const std::string& message)
            : std::runtime_error(message) {}
};



#endif //EX4_EXCEPTION_H
