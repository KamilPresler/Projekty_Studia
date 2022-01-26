#ifndef PAWN_H
#define PAWN_H
#include "Piece.h"

class Pawn: public Piece {
public:
    Pawn(figure type, bool color);

    virtual ~Pawn();

    bool canMoveTo(SquarePtr startSquare, SquarePtr endSquare, Board &gameboard)override;



};


#endif //PAWN_H
