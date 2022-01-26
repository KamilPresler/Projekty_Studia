#include "model/Square.h"
#include "model/Pawn.h"
#include "model/Board.h"
#include <iostream>

Pawn::Pawn(Piece::figure type, bool color) : Piece(type, color) {}

Pawn::~Pawn() {

}

bool Pawn::canMoveTo(SquarePtr startSquare, SquarePtr endSquare, Board &gameboard) {
    int startRow=(startSquare->getNr()/8+1);
    int startColumn=startSquare->getNr()-(startRow-1)*8+1;
    int endRow=endSquare->getNr()/8+1;
    int endColumn=endSquare->getNr()-(endRow-1)*8+1;
    PiecePtr end = endSquare->getPiece();
    if (end== nullptr) {
        if (startColumn == endColumn) {
            if (isColor() == 0) {
                if (endRow == startRow + 1) {
                    return true;
                }
            } else {
                if (endRow == startRow - 1) {
                    return true;
                }
            }
        }
    } else {
        if ((startColumn == endColumn + 1) || (startColumn == endColumn - 1)) {
            if (isColor() == 0) {
                if (endRow == startRow + 1) {
                    return true;
                }
            } else {
                if (endRow == startRow - 1) {
                    return true;
                }
            }
        }
    }
    return false;

    }


