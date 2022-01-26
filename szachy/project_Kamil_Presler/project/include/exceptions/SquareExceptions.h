//
// Created by student on 05.07.2021.
//

#ifndef SquareEXCEPTION_H
#define SquareEXCEPTION_H
#include <stdexcept>

class SquareException : public std::logic_error {
public:

    explicit SquareException(const std::string &arg);
    ~SquareException() noexcept override;
    const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT override;
};

#endif //SquareEXCEPTION_H
