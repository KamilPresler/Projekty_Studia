//
// Created by student on 04.07.2021.
//
#include <boost/test/unit_test.hpp>
#include "typedefs.h"
#include "model/Rook.h"
#include "model/Board.h"
#include "model/Square.h"
using namespace std;
struct RookFixture
{shared_ptr<Rook>WTest;
    shared_ptr<Rook>BTest;
    RookFixture()
    {
        WTest=make_shared<Rook>(Piece::Rook,0);
        BTest=make_shared<Rook>(Piece::Rook,1);
    }
};
BOOST_FIXTURE_TEST_SUITE(TestSuiteRook,RookFixture)
BOOST_AUTO_TEST_CASE(RookGetTypeTest) {
    BOOST_TEST(WTest->getType() == Piece::Rook);
        BOOST_TEST(BTest->getType() == Piece::Rook);
}
    BOOST_AUTO_TEST_CASE(RookIsColorTest) {
        BOOST_TEST(WTest->isColor()== 0);
        BOOST_TEST(BTest->isColor()== 1);
    }
    BOOST_AUTO_TEST_CASE(RookCanMoveToTest)
    {
        Board board;
board.getSquare(0)->setPiece(WTest);
BOOST_TEST(board.getSquare(0)->getPiece()!=nullptr);
BOOST_TEST(board.getSquare(0)->getPiece()->isColor()==0);
BOOST_TEST(WTest->canMoveTo(board.getSquare(0),board.getSquare(8),board)==true);
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
BOOST_TEST(WTest->canMoveTo(board.getSquare(8),board.getSquare(24),board)==true);
        board.getSquare(16)->setPiece(BTest);
        BOOST_TEST(WTest->canMoveTo(board.getSquare(8),board.getSquare(24),board)==false);

    }

BOOST_AUTO_TEST_SUITE_END()