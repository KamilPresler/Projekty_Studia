#include "model/Queen.h"
#include "model/Square.h"
#include "model/Board.h"
Queen::Queen(Piece::figure type, bool color) : Piece(type, color) {}

bool Queen::canMoveTo(SquarePtr startSquare, SquarePtr endSquare, Board &gameboard) {
    int startRow=(startSquare->getNr()/8+1);
    int startColumn=startSquare->getNr()-(startRow-1)*8+1;
    int endRow=endSquare->getNr()/8+1;
    int endColumn=endSquare->getNr()-(endRow-1)*8+1;
    if(startColumn!=3 && startColumn!=6)
    {
        if ((endRow >= 5) && (startRow < 4))return false;
        if ((endRow > 5) && (startRow == 4))return false;
        if ((endRow > 6) && (startRow == 5))return false;
        if ((endRow < 4) && (startRow == 5))return false;
        if ((endRow < 3) && (startRow == 4))return false;
        if ((endRow < 3) && (startRow > 3))return false;
    }
    if(startRow==4|| startRow==5)
    {
        if(abs(startColumn-endColumn)==1)return true;
        else return false;
    }
    if (startRow == endRow) {
        int columnOffSet = (endColumn - startColumn > 0) ? 1 : -1;
        for (int checkColumn = startColumn + columnOffSet; checkColumn !=  endColumn; checkColumn = checkColumn + columnOffSet) {
            if (gameboard.getSquare((startRow-1)*8+checkColumn-1)->getPiece() != nullptr) {
                return false;
            }
        }
        return true;
    } else if (endColumn == startColumn) {
        int rowOffset = (endRow - startRow > 0) ? 1 : -1;
        for (int checkRow = startRow + rowOffset; checkRow !=  endRow; checkRow = checkRow + rowOffset) {
            if (gameboard.getSquare((checkRow-1)*8+startColumn-1)->getPiece()!= nullptr) {
                return false;
            }
        }
        return true;
    }
    if ((endColumn - startColumn == endRow - startRow) || (endColumn - startColumn == startRow - endRow)) {
        int rowOffset = (endRow - startRow > 0) ? 1 : -1;
        int colOffset = (endColumn - startColumn > 0) ? 1 : -1;
        int checkRow;
        int checkColumn;
        for (checkRow = startRow + rowOffset, checkColumn = startColumn + colOffset;
             checkRow !=  endRow;
             checkRow = checkRow + rowOffset, checkColumn = checkColumn + colOffset)
        {
            if (gameboard.getSquare((checkRow-1)*8+checkColumn-1)->getPiece()!= nullptr) {
                return false;
            }
        }
        return true;
    }
    return false;
}

Queen::~Queen() {

}
