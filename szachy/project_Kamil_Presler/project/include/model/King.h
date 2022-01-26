#ifndef KING_H
#define KING_H
#include "Piece.h"

class King: public Piece {
private:
public:

    King(figure type, bool color);

    virtual ~King();

    bool canMoveTo(SquarePtr startSquare, SquarePtr endSquare, Board &gameboard)override;
};


#endif //KING_H
