#include "model/Piece.h"
#include "model/Board.h"
#include "model/Game.h"
#include <iostream>

Piece::Piece(Piece::figure type, bool color) : type(type), color(color) {}

Piece::~Piece() {

}

Piece::figure Piece::getType() const {
    return type;
}

bool Piece::isColor() const {
    return color;
}

bool Piece::moveTo(SquarePtr startSquare, SquarePtr endSquare, Board &gameboard) {
    if(startSquare->getPiece()!= nullptr &&startSquare->getPiece()->isColor()==isColor())
if(endSquare->getPiece()== nullptr||endSquare->getPiece()->isColor()!=isColor())
    {
        return canMoveTo(startSquare, endSquare, gameboard);
    }
return false;
}



