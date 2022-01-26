#ifndef ROOK_H
#define ROOK_H
#include "Piece.h"

class Rook: public Piece {
public:
    Rook(figure type, bool color);

    virtual ~Rook();

    bool canMoveTo(SquarePtr startSquare, SquarePtr endSquare, Board &gameboard)override;

};


#endif //ROOK_H
