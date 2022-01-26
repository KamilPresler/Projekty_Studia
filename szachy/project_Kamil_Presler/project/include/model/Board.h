#ifndef BOARD_H
#define BOARD_H
#include "typedefs.h"
#include <vector>
class Board {
private: std:: vector <SquarePtr>squares;
public:
    SquarePtr getSquare(int nr);
Board();
    virtual ~Board();
    void setStartPieces();

};


#endif //BOARD_H
