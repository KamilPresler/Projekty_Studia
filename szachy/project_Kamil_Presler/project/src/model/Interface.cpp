//
// Created by student on 02.07.2021.
//

#include "model/Interface.h"
#include "model/Game.h"
#include "exceptions/PlayerException.h"
#include <iostream>
#include <string>
#include "exceptions/GameExceptions.h"
using namespace std;


int Interface::convertToSquare(int selection) {
    return (selection/10-1)*8+(selection%10)-1;
}


void Interface::drawBoard(Board gameboard) {

    const int Length = 4;
    const int Width = 3;
    for (int row = 8; row >0; row--) {
        for (int i=0; i< Width; i++) {
            if(i==Width/2)cout<<row<<" ";
            else cout<<"  ";
            for (int column = 1; column <= 8; column++) {
            if((row==5)||(row==4)){
                if((column==3)||(column==6)){ for (int j = 0; j < Length; j++)
                        if(i==Width/2 && j==Length/2-1 && gameboard.getSquare((row-1)*8+(column-1))->getPiece()!= nullptr)
                        {cout<<drawPieces(gameboard.getSquare((row-1)*8+(column-1)));
                            j++;}
                        else
                    cout << "|";}
                else
                {for (int j = 0; j < Length; j++)
                        if(i==Width/2 && j==Length/2-1 && gameboard.getSquare((row-1)*8+(column-1))->getPiece()!= nullptr)
                        {cout<<drawPieces(gameboard.getSquare((row-1)*8+(column-1)));
                            j++;}
                        else
                        cout << "~";}}
            else if ((column+row)% 2 != 1) {
                    for (int j = 0; j < Length; j++)
                        if(i==Width/2 && j==Length/2-1 && gameboard.getSquare((row-1)*8+(column-1))->getPiece()!= nullptr)
                        {cout<<drawPieces(gameboard.getSquare((row-1)*8+(column-1)));
                        j++;}
                        else
                            cout << "*";
                }
             else {
                    for (int j = 0; j < Length; j++)
                        if(i==Width/2 && j==Length/2-1 && gameboard.getSquare((row-1)*8+(column-1))->getPiece()!= nullptr)
                        {cout<<drawPieces(gameboard.getSquare((row-1)*8+(column-1)));
                            j++;}
                        else
                        cout << " ";
                }
            }cout<<endl;
        }

        cout<<endl;
    }
    for(int column=1;column<=8;column++)
    {
        for (int j = 0; j < Length-1; j++)cout << " ";
        cout<<column;
    }

}

void Interface::instructions() {
    cout<<"INSTRUKCJA I ZASADY"<<endl<<endl;
    cout<<"TYPY POL I ICH OZNACZENIA"<<endl;
    cout<<" * -> biale pole"<<endl;
    cout<<" puste pole-czarne pole"<<endl;
    cout<<"~->rzeka,spowalniajaca figury"<<endl;
    cout<<"|->most,po którym figury poruszaja sie normalnie"<<endl<<endl;;
    cout<<"TYPY FIGUR I ICH OZNACZENIA"<<endl;
    cout<<" WP = Bialy Pionek &  BP = Czarny Pionek"<<endl;
    cout<<" WN = Bialy Rycerz & BN = Czarny Rycerz"<<endl;
    cout<<" WB = Bialy Goniec & BB = Czarny Goniec"<<endl;
    cout<<" WR = Biala Wieza & BR = Czarna Wieza"<<endl;
    cout<<" WQ = Bialy Hetman & BQ = Czarny Hetman"<<endl;
    cout<<" WK = Bialy Krol & BK =Czarny Krol"<<endl<<endl;
    cout<<"PORUSZANIE SIE"<<endl;
    cout<<"Na zwyklych polach figury poruszaja sie jak w szachach z wylaczeniem specjalnych ruchow."<<endl;
    cout<<"Na rzece figury poruszaja sie jedynie o jedno pole.Tylko rycerz porusza się normalnie."<<endl;
    cout<<"Aby wykonac ruch podaj rzad a nastepnie kolumne na ktorej znajduje sie fiugra"<<endl<<endl;
    cout<<"CEL GRY"<<endl;
    cout<<"Aby wygrac zbij krola przeciwnika lub wprowadz swojego pionka na linie przeciwnika"<<endl<<endl;
    cout<<"Po kilku sekundach rozpocznie sie rozgrywka"<<endl;

}



string Interface::drawPieces(SquarePtr s) {

    if(s->getPiece()->getType()==Piece::Pawn &&s->getPiece()->isColor()==0)return "WP";
    if(s->getPiece()->getType()==Piece::Pawn &&s->getPiece()->isColor()==1)return "BP";
    if(s->getPiece()->getType()==Piece::Bishop &&s->getPiece()->isColor()==0)return "WB";
    if(s->getPiece()->getType()==Piece::Bishop &&s->getPiece()->isColor()==1)return "BB";
    if(s->getPiece()->getType()==Piece::King &&s->getPiece()->isColor()==0)return "WK";
    if(s->getPiece()->getType()==Piece::King &&s->getPiece()->isColor()==1)return "BK";
    if(s->getPiece()->getType()==Piece::Queen &&s->getPiece()->isColor()==0)return "WQ";
    if(s->getPiece()->getType()==Piece::Queen &&s->getPiece()->isColor()==1)return "BQ";
    if(s->getPiece()->getType()==Piece::Knight &&s->getPiece()->isColor()==0)return "WN";
    if(s->getPiece()->getType()==Piece::Knight &&s->getPiece()->isColor()==1)return "BN";
    if(s->getPiece()->getType()==Piece::Rook &&s->getPiece()->isColor()==0)return "WR";
    if(s->getPiece()->getType()==Piece::Rook &&s->getPiece()->isColor()==1)return "BR";
}

void Interface::showResult(bool result) {
    if(result==1)cout<<"Wygral gracz 2"<<endl;
    if(result==0)cout<<"Wygral gracz 1"<<endl;
}

void Interface::selectPlayers(PlayerPtr P1, PlayerPtr P2) {
    string Name1,Name2;
    string Type1,Type2;
    cout<<"Podaj nazwe pierwszego gracza"<<endl;
    cin.sync();getline(cin,Name1);

    P1->setName(Name1);
    cout<<"Podaj typ pierwszego gracza: 0-czlowiek 1-komputer"<<endl;
    cin.sync();
    getline(cin,Type1);
    if(Type1=="0"|| Type1=="1")
    {
        if(Type1=="0")P1->setPlayerType(false);
        else P1->setPlayerType(true);
        cout<<"Podaj nazwe drugiego gracza"<<endl;
        cin.sync();
        getline(cin,Name2);
        P2->setName(Name2);
    cout<<"Podaj typ drugiego gracza: 0-czlowiek 1-komputer"<<endl;
        cin.sync();
    getline(cin,Type2);
        if(Type1=="0"|| Type1=="1")
        {
            if(Type2=="0")P2->setPlayerType(false);
            else P2->setPlayerType(true);}
    else throw PlayerException("Podano zly typ gracza ");
    }
    else throw PlayerException("Podano zly typ gracza ");



}

Interface::Interface() {}

void Interface::whoseMove(PlayerPtr Player) {

    cout<<endl<<endl<<"Ruch "<<Player->getName()<<endl;

}

Interface::~Interface() {

}

bool Interface::selectGameType() {
    string gameType;
    cout<<"Czy chcesz wczytac gre? 0-nie 1-tak"<<endl;
    cin.sync();
    getline(cin,gameType);
    if(gameType=="0"||gameType=="1")
    {  if(gameType=="0")return false;
    else return true;
}

    else throw GameException("Podano zly typ gry ");
}

int Interface::selectTime() {
    string gameTime;
    cout<<"Podaj czas gry"<<endl;
    cin.sync();
    getline(cin,gameTime);
 int time=stoi(gameTime);
 return time;

}

void Interface::remainingTime(PlayerPtr Player,int time) {
    if (Player->isPlayerType() == 0) {
        cout << endl;
        cout << "Czas: " << Player->timeLeft(time)<<endl;

    }
}



