//
// Created by student on 04.07.2021.
//

#ifndef PROJECT_PLAYER_H
#define PROJECT_PLAYER_H
#include <string>

class Player {
    std::string name;
    bool pieceColor;
    bool playerType=false;
    int turnTime=0;
public:
    void setName(const std::string &name);

    Player(bool pieceColor);

    bool isPlayerType() const;

    virtual ~Player();

    const std::string &getName() const;

    bool isPieceColor() const;

    void setPlayerType(bool playerType);

    int timeLeft(int gameTime);

    int getTurnTime() const;

    void addTurnTime(int turnTime);


};


#endif //PROJECT_PLAYER_H
