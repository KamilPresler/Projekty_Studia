//
// Created by student on 05.07.2021.
//

#include "exceptions/SquareExceptions.h"

SquareException::SquareException(const std::string &arg) : logic_error(arg) {}

SquareException::~SquareException() noexcept = default;

const char *SquareException::what() const noexcept {
    return logic_error::what();
}