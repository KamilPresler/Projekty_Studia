//
// Created by student on 04.07.2021.
//
#include <boost/test/unit_test.hpp>
#include "typedefs.h"
#include "model/Bishop.h"
#include "model/Board.h"
#include "model/Square.h"
using namespace std;
struct BishopFixture
{shared_ptr<Bishop>WTest;
    shared_ptr<Bishop>BTest;
    BishopFixture()
    {
        WTest=make_shared<Bishop>(Piece::Bishop,0);
        BTest=make_shared<Bishop>(Piece::Bishop,1);
    }
};
BOOST_FIXTURE_TEST_SUITE(TestSuiteBishop,BishopFixture)
    BOOST_AUTO_TEST_CASE(BishopGetTypeTest) {
        BOOST_TEST(WTest->getType() == Piece::Bishop);
        BOOST_TEST(BTest->getType() == Piece::Bishop);
    }
    BOOST_AUTO_TEST_CASE(BishopIsColorTest) {
        BOOST_TEST(WTest->isColor()== 0);
        BOOST_TEST(BTest->isColor()== 1);
    }
    BOOST_AUTO_TEST_CASE(BishopCanMoveToTest)
    {
        Board board;
        board.getSquare(0)->setPiece(WTest);
        BOOST_TEST(board.getSquare(0)->getPiece()!=nullptr);
        BOOST_TEST(board.getSquare(0)->getPiece()->isColor()==0);
        BOOST_TEST(WTest->canMoveTo(board.getSquare(0),board.getSquare(8),board)==false);
        BOOST_TEST(WTest->canMoveTo(board.getSquare(0),board.getSquare(9),board)==true);
        BOOST_TEST(WTest->canMoveTo(board.getSquare(0),board.getSquare(27),board)==true);
        board.getSquare(8)->setPiece(BTest);
        BOOST_TEST(board.getSquare(8)->getPiece()!=nullptr);
        BOOST_TEST(board.getSquare(8)->getPiece()->isColor()==1);
        BOOST_TEST(WTest->canMoveTo(board.getSquare(8),board.getSquare(1),board)==true);
        BOOST_TEST(WTest->canMoveTo(board.getSquare(8),board.getSquare(12),board)==false);
        board.getSquare(0)->resetPiece();
        BOOST_TEST(board.getSquare(0)->getPiece()==nullptr);
        board.getSquare(17)->setPiece(WTest);
        BOOST_TEST(BTest->canMoveTo(board.getSquare(8),board.getSquare(26),board)==false);

    }
BOOST_AUTO_TEST_SUITE_END()