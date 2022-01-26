#include "model/Board.h"
#include "model/Square.h"
#include <iostream>
#include "typedefs.h"
#include "model/Pawn.h"
#include "model/Knight.h"
#include "model/Queen.h"
#include "model/King.h"
#include "model/Rook.h"
#include "model/Bishop.h"
using namespace std;
Board::~Board() {

}
Board::Board() {
    for(int n=0; n<64;n++)
    {
        SquarePtr square= make_shared<Square>(n);
        squares.push_back(square);

    }
}

SquarePtr Board::getSquare(int nr) {
    return squares[nr];
}

void Board::setStartPieces() {
    PawnPtr WP1 (new Pawn(Piece::Pawn,0));
    PawnPtr WP2 (new Pawn(Piece::Pawn,0));
    PawnPtr WP3 (new Pawn(Piece::Pawn,0));
    PawnPtr WP4 (new Pawn(Piece::Pawn,0));
    PawnPtr WP5 (new Pawn(Piece::Pawn,0));
    PawnPtr WP6 (new Pawn(Piece::Pawn,0));
    PawnPtr WP7 (new Pawn(Piece::Pawn,0));
    PawnPtr WP8 (new Pawn(Piece::Pawn,0));
    PawnPtr BP1 (new Pawn(Piece::Pawn,1));
    PawnPtr BP2 (new Pawn(Piece::Pawn,1));
    PawnPtr BP3 (new Pawn(Piece::Pawn,1));
    PawnPtr BP4 (new Pawn(Piece::Pawn,1));
    PawnPtr BP5 (new Pawn(Piece::Pawn,1));
    PawnPtr BP6 (new Pawn(Piece::Pawn,1));
    PawnPtr BP7 (new Pawn(Piece::Pawn,1));
    PawnPtr BP8 (new Pawn(Piece::Pawn,1));
    KnightPtr WN1 (new Knight(Piece::Knight,0));
    KnightPtr WN2 (new Knight(Piece::Knight,0));
    KnightPtr BN1 (new Knight(Piece::Knight,1));
    KnightPtr BN2 (new Knight(Piece::Knight,1));
    BishopPtr WB1 (new Bishop(Piece::Bishop,0));
    BishopPtr WB2 (new Bishop(Piece::Bishop,0));
    BishopPtr BB1 (new Bishop(Piece::Bishop,1));
    BishopPtr BB2 (new Bishop(Piece::Bishop,1));
    RookPtr WR1 (new Rook(Piece::Rook,0));
RookPtr WR2(new Rook(Piece::Rook,0));
    RookPtr BR1 (new Rook(Piece::Rook,1));
    RookPtr BR2 (new Rook(Piece::Rook,1));
    KingPtr WK(new King(Piece::King,0));
    KingPtr BK(new King(Piece::King,1));
    QueenPtr WQ(new Queen(Piece::Queen,0));
    QueenPtr BQ(new Queen(Piece::Queen,1));
    getSquare(8)->setPiece(WP1);
    getSquare(9)->setPiece(WP2);
    getSquare(10)->setPiece(WP3);
    getSquare(11)->setPiece(WP4);
    getSquare(12)->setPiece(WP5);
    getSquare(13)->setPiece(WP6);
    getSquare(14)->setPiece(WP7);
    getSquare(15)->setPiece(WP8);
    getSquare(48)->setPiece(BP1);
    getSquare(49)->setPiece(BP2);
    getSquare(50)->setPiece(BP3);
    getSquare(51)->setPiece(BP4);
    getSquare(52)->setPiece(BP5);
    getSquare(53)->setPiece(BP6);
    getSquare(54)->setPiece(BP7);
    getSquare(55)->setPiece(BP8);
    getSquare(1)->setPiece(WN1);
    getSquare(6)->setPiece(WN2);
    getSquare(57)->setPiece(BN1);
    getSquare(62)->setPiece(BN2);
    getSquare(2)->setPiece(WB1);
    getSquare(5)->setPiece(WB2);
    getSquare(58)->setPiece(BB1);
    getSquare(61)->setPiece(BB2);
    getSquare(0)->setPiece(WR1);
    getSquare(7)->setPiece(WR1);
    getSquare(56)->setPiece(BR1);
    getSquare(63)->setPiece(BR2);
    getSquare(4)->setPiece(WK);
    getSquare(60)->setPiece(BK);
    getSquare(3)->setPiece(WQ);
    getSquare(59)->setPiece(BQ);
}
