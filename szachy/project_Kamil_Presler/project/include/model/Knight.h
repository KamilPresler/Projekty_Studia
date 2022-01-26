#ifndef KNIGHT_H
#define KNIGHT_H
#include "Piece.h"

class Knight :public Piece {
public:
    Knight(figure type, bool color);

    virtual ~Knight();

    bool canMoveTo(SquarePtr startSquare, SquarePtr endSquare, Board &gameboard)override;

};


#endif //KNIGHT_H
