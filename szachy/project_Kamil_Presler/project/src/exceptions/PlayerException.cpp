//
// Created by student on 11.06.2021.
//

#include "exceptions/PlayerException.h"

PlayerException::PlayerException(const std::string &arg) : logic_error(arg) {}

PlayerException::~PlayerException() noexcept = default;

const char *PlayerException::what() const noexcept {
    return logic_error::what();
}