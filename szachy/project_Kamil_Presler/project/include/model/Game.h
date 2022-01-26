//
// Created by student on 03.07.2021.
//

#ifndef GAME_H
#define GAME_H
#include "Board.h"
#include "typedefs.h"
#include "Interface.h"
#include "UserInterface.h"
#include "ComputerInterface.h"
#include "Piece.h"
#include "Player.h"
#include <fstream>

#include <boost/date_time.hpp>



#include <vector>

class Game {
private:
    Board gameboard;
    InterfacePtr interface;
    UserInterface ui;
    ComputerInterface ci;
    bool result=false;
    bool load=false;
    PlayerPtr P1,P2;
    PlayerPtr currentPlayer =P1;
    int time;

public:
    Game(const PlayerPtr &p1, const PlayerPtr &p2);

    void play();
    bool forceCapture();
    void forceMove(int start,int end);
    bool addMove(int start,int end);
    void setResult(bool result);
    bool computerMove();
    bool humanMove();
    void saveMove(int start,int end);
    void savePlayers();
   void loadGame();
void loadPlayers(std::ifstream &plik,PlayerPtr P);
void loadMove(std::ifstream&plik);
    void setIsLoad(bool load);

    bool isLoad() const;

    int getTime() const;

    void setTime(int time);

    bool isResult() const;

    void setCurrentPlayer(const PlayerPtr &currentPlayer);
    int getTurnDuration(boost::posix_time::ptime start, boost::posix_time::ptime end);

    virtual ~Game();
};


#endif //GAME_H
