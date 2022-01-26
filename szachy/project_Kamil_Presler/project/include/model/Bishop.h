#ifndef BISHOP_H
#define BISHOP_H
#include "Piece.h"

class Bishop: public Piece {
public:
    Bishop(figure type, bool color);

    virtual ~Bishop();
    bool canMoveTo(SquarePtr startSquare, SquarePtr endSquare, Board &gameboard)override;

};


#endif //BISHOP_H
