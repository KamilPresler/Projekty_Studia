//
// Created by student on 04.07.2021.
//
#include <boost/test/unit_test.hpp>
#include "typedefs.h"
#include "model/Pawn.h"
#include "model/Board.h"
#include "model/Square.h"
using namespace std;
struct PawnFixture
{shared_ptr<Pawn>WTest;
    shared_ptr<Pawn>BTest;
    PawnFixture()
    {
        WTest=make_shared<Pawn>(Piece::Pawn,0);
        BTest=make_shared<Pawn>(Piece::Pawn,1);
    }
};
BOOST_FIXTURE_TEST_SUITE(TestSuitePawn,PawnFixture)
    BOOST_AUTO_TEST_CASE(PawnGetTypeTest) {
        BOOST_TEST(WTest->getType() == Piece::Pawn);
        BOOST_TEST(BTest->getType() == Piece::Pawn);
    }
    BOOST_AUTO_TEST_CASE(PawnIsColorTest) {
        BOOST_TEST(WTest->isColor()== 0);
        BOOST_TEST(BTest->isColor()== 1);
    }
    BOOST_AUTO_TEST_CASE(PawnCanMoveToTest)
    {Board board;
        board.getSquare(10)->setPiece(WTest);
        BOOST_TEST(board.getSquare(10)->getPiece()!=nullptr);
        BOOST_TEST(board.getSquare(10)->getPiece()->isColor()==0);
        BOOST_TEST(WTest->canMoveTo(board.getSquare(10),board.getSquare(2),board)==false);
        BOOST_TEST(WTest->canMoveTo(board.getSquare(10),board.getSquare(18),board)==true);
        BOOST_TEST(WTest->canMoveTo(board.getSquare(10),board.getSquare(19),board)==false);
        board.getSquare(19)->setPiece(BTest);
        BOOST_TEST(WTest->canMoveTo(board.getSquare(10),board.getSquare(19),board)==true);
        board.getSquare(19)->resetPiece();
        BOOST_TEST(board.getSquare(19)->getPiece()==nullptr);
        board.getSquare(18)->setPiece(BTest);
        BOOST_TEST(WTest->canMoveTo(board.getSquare(10),board.getSquare(18),board)==false);
    }
BOOST_AUTO_TEST_SUITE_END()