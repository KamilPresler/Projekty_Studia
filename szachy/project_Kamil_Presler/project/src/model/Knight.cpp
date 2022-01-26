#include "model/Knight.h"
#include "model/Square.h"
#include "model/Board.h"
Knight::Knight(Piece::figure type, bool color) : Piece(type, color) {}

bool Knight::canMoveTo(SquarePtr startSquare, SquarePtr endSquare, Board &gameboard) {
    int startRow=(startSquare->getNr()/8+1);
    int startColumn=startSquare->getNr()-(startRow-1)*8+1;
    int endRow=endSquare->getNr()/8+1;
    int endColumn=endSquare->getNr()-(endRow-1)*8+1;
    if ((startColumn == endColumn + 1) || (startColumn == endColumn - 1)) {
        if ((startRow == endRow + 2) || (startRow == endRow - 2)) {
            return true;
        }
    }
    if ((startColumn == endColumn + 2) || (startColumn == endColumn - 2)) {
        if ((startRow == endRow + 1) || (startRow == endRow - 1)) {
            return true;
        }
    }
    return false;
}

Knight::~Knight() {

}

