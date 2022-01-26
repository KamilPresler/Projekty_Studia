//
// Created by student on 11.06.2021.
//

#ifndef PlayerEXCEPTION_H
#define PlayerEXCEPTION_H
#include <stdexcept>

class PlayerException : public std::logic_error {
public:

    explicit PlayerException(const std::string &arg);
    ~PlayerException() noexcept override;
     const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT override;
};

#endif //PlayerEXCEPTION_H
