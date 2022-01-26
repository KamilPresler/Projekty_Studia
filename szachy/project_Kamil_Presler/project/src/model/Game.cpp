//
// Created by student on 03.07.2021.
//

#include <iostream>
#include "model/Game.h"
#include "model/Board.h"
#include "model/Interface.h"
#include <fstream>
#include "model/UserInterface.h"
#include "model/ComputerInterface.h"
#include "model/Player.h"
#include <unistd.h>
#include "exceptions/GameExceptions.h"
#include <sstream>
namespace pt = boost::posix_time;
bool Game::forceCapture() {
    bool force=false;
    for(int i=40;i<=63;i++)
    {   for(int j=0;j<=63;j++) {
            if (gameboard.getSquare(i)->getPiece() != nullptr) {
                if (currentPlayer->isPieceColor() == 1 && gameboard.getSquare(i)->getPiece()->isColor() != currentPlayer->isPieceColor()) {
                    if (gameboard.getSquare(j)->getPiece()->moveTo(gameboard.getSquare(j), gameboard.getSquare(i),
                                                                   gameboard) == true)
                        force = true;
                };
            }
                if (gameboard.getSquare(63-i)->getPiece() != nullptr) {
                    if (currentPlayer->isPieceColor() == 0 && gameboard.getSquare(63-i)->getPiece()->isColor() != currentPlayer->isPieceColor()) {
                        if(gameboard.getSquare(j)->getPiece()->moveTo(gameboard.getSquare(j),gameboard.getSquare(63-i),gameboard)==true) force=true;
                    };
            }
        }
    };return force;
}
void Game::forceMove(int start, int end) {
    if(gameboard.getSquare(end)->getPiece()!= nullptr)
    {
        if((currentPlayer->isPieceColor()==0&&end>=0&&end<=23)||(currentPlayer->isPieceColor()==1&&end>=40&&end<=63))
        {
            if (gameboard.getSquare(start)->getPiece()->moveTo(
                    gameboard.getSquare(start), gameboard.getSquare(end),
                    gameboard) == 0) {

            } else if (gameboard.getSquare(start)->getPiece()->isColor() == currentPlayer->isPieceColor()) {
                gameboard.getSquare(end)->setPiece(
                        gameboard.getSquare(start)->getPiece());
                gameboard.getSquare(start)->resetPiece();
            }
        }
        else
        {
ui.error();
        }
    }
    else
    {
ui.error();
    };
}


bool Game::addMove(int start,int end) {
   bool validMove=false;
        if (forceCapture() == true) { forceMove(start, end); ; }
        else {
            if (gameboard.getSquare(start)->getPiece()->moveTo(
                    gameboard.getSquare(start),
                    gameboard.getSquare(end),
                    gameboard) == 0) {


            } else if (gameboard.getSquare(start)->getPiece()->isColor() ==
                       currentPlayer->isPieceColor()) {
                gameboard.getSquare(end)->setPiece(
                        gameboard.getSquare(start)->getPiece());
                gameboard.getSquare(start)->resetPiece();
                validMove = true;

            }
        }
        if (validMove == false && currentPlayer->isPlayerType() == 0)ui.error();


    return validMove;}



void Game::play() {
    gameboard.setStartPieces();
    interface->instructions();
     sleep(10);
    loadGame();
    setTime(interface->selectTime());
   if(isLoad()==false)
   {interface->selectPlayers(P1, P2);
   savePlayers();}
    interface->drawBoard(gameboard);

    do {
        bool firstKingExist = false;
        bool secondKingExist = false;
        bool whitePawnPromoted = false;
        bool blackPawnPromoted = false;
        interface->remainingTime(currentPlayer,getTime());
        for (int i = 0; i <= 63; i++)
            if (gameboard.getSquare(i)->getPiece() != nullptr) {
                if (gameboard.getSquare(i)->getPiece()->getType() == Piece::King &&
                    gameboard.getSquare(i)->getPiece()->isColor() == 0)
                    firstKingExist = true;
                if (gameboard.getSquare(i)->getPiece()->getType() == Piece::King &&
                    gameboard.getSquare(i)->getPiece()->isColor() == 1)
                    secondKingExist = true;
            }
        for (int i = 0; i < 8; i++) {
            if (gameboard.getSquare(i)->getPiece() != nullptr)
                if (gameboard.getSquare(i)->getPiece()->getType() == Piece::Pawn &&
                    gameboard.getSquare(i)->getPiece()->isColor() == 1)
                    blackPawnPromoted = true;
            if (gameboard.getSquare(63 - i)->getPiece() != nullptr)
                if (gameboard.getSquare(63 - i)->getPiece()->getType() == Piece::Pawn &&
                    gameboard.getSquare(63 - i)->getPiece()->isColor() == 0)
                    whitePawnPromoted = true;
        }
        if (firstKingExist == false || secondKingExist == false) {
            interface->showResult(secondKingExist);
            setResult(result);
        } else if (whitePawnPromoted == true || blackPawnPromoted == true) {
            interface->showResult(blackPawnPromoted);
            setResult(result);}
            else if(currentPlayer->getTurnTime()>getTime()&&currentPlayer->isPieceColor()==0)
            {interface->showResult(true);
                setResult(result);}
            else if(currentPlayer->getTurnTime()>getTime()&&currentPlayer->isPieceColor()==1)
            {interface->showResult(false);
                setResult(result);}
         else {
            if (currentPlayer->isPlayerType()==0)
            {if(humanMove()==true)
            {interface->drawBoard(gameboard);
                if (currentPlayer->isPieceColor() == 0)setCurrentPlayer(P2);
                else if (currentPlayer->isPieceColor() == 1)setCurrentPlayer(P1);
            }

            }
            if (currentPlayer->isPlayerType()==1)
            {if(computerMove()==true)
                {interface->drawBoard(gameboard);
                    if (currentPlayer->isPieceColor() == 0)setCurrentPlayer(P2);
                    else if (currentPlayer->isPieceColor() == 1)setCurrentPlayer(P1);
                }

            }

        }
    }
    while (isResult() == 0);

}

void Game::setResult(bool result) {
    Game::result = !result;
}



void Game::setCurrentPlayer(const PlayerPtr &currentPlayer) {
    Game::currentPlayer = currentPlayer;
}

Game::Game(const PlayerPtr &p1, const PlayerPtr &p2) : P1(p1), P2(p2) {}

Game::~Game() {

}

bool Game::computerMove() {
    pt::ptime startTurn,endTurn;
    startTurn=pt::second_clock::local_time();
   int start=interface->convertToSquare(ci.selectStartSquare());

    int end=64;
    if(gameboard.getSquare(start)->getPiece()!= nullptr)
    {
        if(gameboard.getSquare(start)->getPiece()->isColor()==currentPlayer->isPieceColor())
        {
            for(int i=0;i<63;i++)
                {
                if(gameboard.getSquare(start)->getPiece()->moveTo(gameboard.getSquare(start),gameboard.getSquare(i),gameboard)==true) end=i;
                }
        }
    }if(end==64)ci.selectEndSquare();
   if(end!=64)
   {
      if(addMove(start,end)==true)
      {endTurn=pt::second_clock::local_time();
          currentPlayer->addTurnTime(getTurnDuration(startTurn,endTurn));
          saveMove(start,end);
       return true;}
   else
      {endTurn=pt::second_clock::local_time();
          currentPlayer->addTurnTime(getTurnDuration(startTurn,endTurn));
       return false;}}
   else {endTurn=pt::second_clock::local_time();
       currentPlayer->addTurnTime(getTurnDuration(startTurn,endTurn));
       return false;
   }

}

bool Game::humanMove() {
    pt::ptime startTurn,endTurn;
    startTurn=pt::second_clock::local_time();
    interface->whoseMove(currentPlayer);
    int start=ui.convertToSquare(ui.selectStartSquare());
    int end=ui.convertToSquare(ui.selectEndSquare());
   if(addMove(start,end)==true)
   {    endTurn=pt::second_clock::local_time();
       currentPlayer->addTurnTime(getTurnDuration(startTurn,endTurn));
       saveMove(start,end);
       return true;
   }
   else
   {endTurn=pt::second_clock::local_time();
       currentPlayer->addTurnTime(getTurnDuration(startTurn,endTurn));}
    return false;
}

void Game::saveMove(int start,int end) {
    std:: ofstream zapis;
    zapis.open("gra.txt",std::ios::app);
    if(zapis.is_open()==true)
    zapis<<start<<" "<<end<<std::endl;
    zapis.close();


}

void Game::savePlayers() {
    std:: ofstream zapis;
    zapis.open("gra.txt",std::ios::out );
    if(zapis.is_open()==true)
        zapis<<P1->getName()<<" "<<P1->isPlayerType()<<std::endl;
    zapis<<P2->getName()<<" "<<P2->isPlayerType()<<std::endl;
    zapis.close();
}

void Game::loadGame() {
if(interface->selectGameType()==true)
    {
        setIsLoad(load);
        std::ifstream zapis;
        zapis.open("gra.txt", std::ios::in);
        if(zapis.good()==true)
        { loadPlayers(zapis, P1);
        loadPlayers(zapis,P2);
        while(zapis.eof()==false)
        { loadMove(zapis);}
            zapis.close();}
        else throw GameException("Nie znaleziono pliku");
    }
}
void Game::loadPlayers(std::ifstream &plik,PlayerPtr P) {
    std::string N1,N2;
    plik>>N1;
    plik>>N2;
    P->setName(N1);
    if(N2=="0")P->setPlayerType(false);
    else if(N2=="1")P->setPlayerType(true);
    else throw GameException("Blad oczytu ");

}

void Game::setIsLoad(bool load) {
    Game::load = !load;
}

void Game::loadMove(std::ifstream &plik) {
    int start,end;
  plik>>start;
  plik>>end;
  if(plik.eof()==false)
  { if((start>=0&&start<=63)&&(end>=0&&end<=63))
      {
  addMove(start,end);
    if (currentPlayer->isPieceColor() == 0)setCurrentPlayer(P2);
    else if (currentPlayer->isPieceColor() == 1)setCurrentPlayer(P1);}
  else throw GameException("Blad oczytu ");
  }
}


int Game::getTime() const {
    return time;
}

bool Game::isResult() const {
    return result;
}

bool Game::isLoad() const {
    return load;
}

void Game::setTime(int time) {
    Game::time = time;
}

int Game::getTurnDuration(boost::posix_time::ptime start, boost::posix_time::ptime end) {
    pt::time_period turnDuration(start, end);
    return turnDuration.length().seconds();
}