#ifndef QUEEN_H
#define QUEEN_H
#include "Piece.h"

class Queen:public Piece {
public:
    Queen(figure type, bool color);

    virtual ~Queen();

    bool canMoveTo(SquarePtr startSquare, SquarePtr endSquare, Board &gameboard)override;

};


#endif //QUEEN_H
