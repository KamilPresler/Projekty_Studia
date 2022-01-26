#include "model/Square.h"
#include <iostream>
Square::Square(int _nr) : nr(_nr)
{
}


Square::~Square() {

}

int Square::getNr() const {
    return nr;
}

const PiecePtr &Square::getPiece() const {
    return piece;
}

void Square::setPiece(const PiecePtr &piece) {
    Square::piece = piece;
}



void Square::resetPiece() {
    Square::piece = nullptr;

}
