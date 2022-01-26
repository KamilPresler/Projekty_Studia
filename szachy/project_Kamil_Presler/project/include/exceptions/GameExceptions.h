//
// Created by student on 05.07.2021.
//

#ifndef GAMEEXCEPTIONS_H
#define GAMEEXCEPTIONS_H
#include <stdexcept>

class GameException : public std::logic_error {
public:

    explicit GameException(const std::string &arg);
    ~GameException() noexcept override;
    const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT override;
};

#endif //GAMEEXCEPTIONS_H
