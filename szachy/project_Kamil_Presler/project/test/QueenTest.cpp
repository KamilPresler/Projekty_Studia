//
// Created by student on 04.07.2021.
//
#include <boost/test/unit_test.hpp>
#include "typedefs.h"
#include "model/Queen.h"
#include "model/Board.h"
#include "model/Square.h"
using namespace std;
struct QueenFixture
{shared_ptr<Queen>WTest;
    shared_ptr<Queen>BTest;
    QueenFixture()
    {
        WTest=make_shared<Queen>(Piece::Queen,0);
        BTest=make_shared<Queen>(Piece::Queen,1);
    }
};
BOOST_FIXTURE_TEST_SUITE(TestSuiteQueen,QueenFixture)
    BOOST_AUTO_TEST_CASE(QueenGetTypeTest) {
        BOOST_TEST(WTest->getType() == Piece::Queen);
        BOOST_TEST(BTest->getType() == Piece::Queen);
    }
    BOOST_AUTO_TEST_CASE(QueenIsColorTest) {
        BOOST_TEST(WTest->isColor()== 0);
        BOOST_TEST(BTest->isColor()== 1);
    }
    BOOST_AUTO_TEST_CASE(QueenCanMoveToTest)
    {Board board;
    board.getSquare(0)->setPiece(WTest);
        BOOST_TEST(board.getSquare(0)->getPiece()!=nullptr);
        BOOST_TEST(board.getSquare(0)->getPiece()->isColor()==0);
        BOOST_TEST(WTest->canMoveTo(board.getSquare(0),board.getSquare(8),board)==true);
        BOOST_TEST(WTest->canMoveTo(board.getSquare(0),board.getSquare(9),board)==true);
        BOOST_TEST(WTest->canMoveTo(board.getSquare(0),board.getSquare(27),board)==true);
        board.getSquare(8)->setPiece(BTest);
        BOOST_TEST(board.getSquare(8)->getPiece()!=nullptr);
        BOOST_TEST(board.getSquare(8)->getPiece()->isColor()==1);
        board.getSquare(8)->setPiece(WTest);
        board.getSquare(0)->resetPiece();
        BOOST_TEST(board.getSquare(0)->getPiece()==nullptr);
        BOOST_TEST(board.getSquare(8)->getPiece()!=nullptr);
        BOOST_TEST(board.getSquare(8)->getPiece()->isColor()==0);
        BOOST_TEST(WTest->canMoveTo(board.getSquare(8),board.getSquare(32),board)==false);
        BOOST_TEST(WTest->canMoveTo(board.getSquare(8),board.getSquare(28),board)==false);
        BOOST_TEST(board.getSquare(0)->getPiece()==nullptr);
        board.getSquare(17)->setPiece(BTest);
        BOOST_TEST(WTest->canMoveTo(board.getSquare(8),board.getSquare(26),board)==false);
        BOOST_TEST(WTest->canMoveTo(board.getSquare(8),board.getSquare(24),board)==true);
        board.getSquare(17)->resetPiece();
        board.getSquare(16)->setPiece(BTest);
        BOOST_TEST(WTest->canMoveTo(board.getSquare(8),board.getSquare(24),board)==false);
    }
BOOST_AUTO_TEST_SUITE_END(

        )