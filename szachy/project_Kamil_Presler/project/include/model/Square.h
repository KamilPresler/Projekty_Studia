#ifndef SQUARE_H
#define SQUARE_H
#include "typedefs.h"
#include "Piece.h"
class Square {
private:
    int nr;
    PiecePtr piece = nullptr;
public:
    Square(int nr);
    virtual ~Square();
    int getNr() const;
    const PiecePtr &getPiece() const;
    void setPiece(const PiecePtr &piece);
    void resetPiece();

};





#endif //SQUARE_H
