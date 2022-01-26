//
// Created by student on 04.07.2021.
//
#include <boost/test/unit_test.hpp>
#include "typedefs.h"
#include "model/King.h"
#include "model/Board.h"
#include "model/Square.h"
using namespace std;
struct KingFixture
{shared_ptr<King>WTest;
    shared_ptr<King>BTest;
    KingFixture()
    {
        WTest=make_shared<King>(Piece::King,0);
        BTest=make_shared<King>(Piece::King,1);
    }
};
BOOST_FIXTURE_TEST_SUITE(TestSuiteKing,KingFixture)
    BOOST_AUTO_TEST_CASE(KingGetTypeTest) {
        BOOST_TEST(WTest->getType() == Piece::King);
        BOOST_TEST(BTest->getType() == Piece::King);
    }
    BOOST_AUTO_TEST_CASE(KingIsColorTest) {
        BOOST_TEST(WTest->isColor()== 0);
        BOOST_TEST(BTest->isColor()== 1);
    }
    BOOST_AUTO_TEST_CASE(KingCanMoveToTest)
    {
        Board board;
        board.getSquare(9)->setPiece(WTest);
        BOOST_TEST(board.getSquare(9)->getPiece()!=nullptr);
        BOOST_TEST(board.getSquare(9)->getPiece()->isColor()==0);
        BOOST_TEST(WTest->canMoveTo(board.getSquare(9),board.getSquare(8),board)==true);
        BOOST_TEST(WTest->canMoveTo(board.getSquare(9),board.getSquare(10),board)==true);
        BOOST_TEST(WTest->canMoveTo(board.getSquare(9),board.getSquare(17),board)==true);
        BOOST_TEST(WTest->canMoveTo(board.getSquare(9),board.getSquare(16),board)==true);
        BOOST_TEST(WTest->canMoveTo(board.getSquare(9),board.getSquare(18),board)==true);
        BOOST_TEST(WTest->canMoveTo(board.getSquare(9),board.getSquare(0),board)==true);
        BOOST_TEST(WTest->canMoveTo(board.getSquare(9),board.getSquare(1),board)==true);
        BOOST_TEST(WTest->canMoveTo(board.getSquare(9),board.getSquare(2),board)==true);
        BOOST_TEST(WTest->canMoveTo(board.getSquare(9),board.getSquare(7),board)==false);
        board.getSquare(9)->resetPiece();
        BOOST_TEST(board.getSquare(9)->getPiece()==nullptr);
        board.getSquare(9)->setPiece(BTest);
        BOOST_TEST(board.getSquare(9)->getPiece()!=nullptr);
        BOOST_TEST(board.getSquare(9)->getPiece()->isColor()==1);

    }
BOOST_AUTO_TEST_SUITE_END()