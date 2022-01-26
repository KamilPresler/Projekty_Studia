#ifndef PIECE_H
#define PIECE_H
#include <cmath>
#include <vector>
#include <memory>
#include "typedefs.h"
class Piece {
public:  enum figure {Rook,Bishop,Knight,Pawn,Queen,King};
private:
    figure type;
    bool color;


public:
    Piece(figure type, bool color);

    bool moveTo(SquarePtr startSquare, SquarePtr endSquare, Board &gameboard);
    virtual bool canMoveTo(SquarePtr startSquare, SquarePtr endSquare, Board &gameboard)=0;

    virtual ~Piece();

    figure getType() const;

    bool isColor() const;



};


#endif //PIECE_H
