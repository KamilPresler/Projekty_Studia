#include "model/King.h"
#include "model/Square.h"
#include "model/Board.h"
King::King(Piece::figure type, bool color) : Piece(type, color) {}

bool King::canMoveTo(SquarePtr startSquare, SquarePtr endSquare, Board &gameboard) {
    int startRow=(startSquare->getNr()/8+1);
    int startColumn=startSquare->getNr()-(startRow-1)*8+1;
    int endRow=endSquare->getNr()/8+1;
    int endColumn=endSquare->getNr()-(endRow-1)*8+1;
    int rowDelta = endRow - startRow;
    int colDelta = endColumn - startColumn;
    if (((rowDelta >= -1) && (rowDelta <= 1)) &&
        ((colDelta >= -1) && (colDelta <= 1)))
    {
        return true;
    }
    return false;
}

King::~King() {

}







