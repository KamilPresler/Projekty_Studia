//
// Created by student on 02.07.2021.
//

#ifndef INTERFACE_H
#define INTERFACE_H
#include "Square.h"
#include "typedefs.h"
#include "Piece.h"
#include "Board.h"
#include "Player.h"
#include <string>
class Interface {

public:
    void whoseMove(PlayerPtr Player);
    virtual int selectStartSquare()=0;
    virtual int selectEndSquare()=0;
    int convertToSquare(int selection);

    void drawBoard(Board gameboard);
    std::string drawPieces(SquarePtr s);
    void showResult(bool result);
    void instructions();
    void selectPlayers(PlayerPtr P1,PlayerPtr P2);
    bool selectGameType();
    int selectTime();
    void remainingTime(PlayerPtr Player,int time);
    Interface();

    virtual ~Interface();
};


#endif //INTERFACE_H
