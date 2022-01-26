//
// Created by student on 05.07.2021.
//

#include "exceptions/GameExceptions.h"
GameException::GameException(const std::string &arg) : logic_error(arg) {}

GameException::~GameException() noexcept = default;

const char *GameException::what() const noexcept {
    return logic_error::what();
}