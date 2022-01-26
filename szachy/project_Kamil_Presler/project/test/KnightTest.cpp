//
// Created by student on 04.07.2021.
//
#include <boost/test/unit_test.hpp>
#include "typedefs.h"
#include "model/Knight.h"
#include "model/Board.h"
#include "model/Square.h"
using namespace std;
struct KnightFixture
{shared_ptr<Knight>WTest;
    shared_ptr<Knight>BTest;
    KnightFixture()
    {
        WTest=make_shared<Knight>(Piece::Knight,0);
        BTest=make_shared<Knight>(Piece::Knight,1);
    }
};
BOOST_FIXTURE_TEST_SUITE(TestSuiteKnight,KnightFixture)
    BOOST_AUTO_TEST_CASE(KnightGetTypeTest) {
        BOOST_TEST(WTest->getType() == Piece::Knight);
        BOOST_TEST(BTest->getType() == Piece::Knight);
    }
    BOOST_AUTO_TEST_CASE(KnightIsColorTest) {
        BOOST_TEST(WTest->isColor()== 0);
        BOOST_TEST(BTest->isColor()== 1);
    }
    BOOST_AUTO_TEST_CASE(KnightCanMoveToTest)
    {
        Board board;
        board.getSquare(27)->setPiece(WTest);
        BOOST_TEST(board.getSquare(27)->getPiece()!=nullptr);
        BOOST_TEST(board.getSquare(27)->getPiece()->isColor()==0);
        board.getSquare(0)->setPiece(BTest);
        BOOST_TEST(board.getSquare(0)->getPiece()!=nullptr);
        BOOST_TEST(board.getSquare(0)->getPiece()->isColor()==1);
        board.getSquare(0)->resetPiece();
        BOOST_TEST(WTest->canMoveTo(board.getSquare(27),board.getSquare(7),board)==false);
        BOOST_TEST(WTest->canMoveTo(board.getSquare(27),board.getSquare(10),board)==true);
        BOOST_TEST(WTest->canMoveTo(board.getSquare(27),board.getSquare(12),board)==true);
        BOOST_TEST(WTest->canMoveTo(board.getSquare(27),board.getSquare(17),board)==true);
        BOOST_TEST(WTest->canMoveTo(board.getSquare(27),board.getSquare(21),board)==true);
        BOOST_TEST(WTest->canMoveTo(board.getSquare(27),board.getSquare(33),board)==true);
        BOOST_TEST(WTest->canMoveTo(board.getSquare(27),board.getSquare(37),board)==true);
        BOOST_TEST(WTest->canMoveTo(board.getSquare(27),board.getSquare(42),board)==true);
        BOOST_TEST(WTest->canMoveTo(board.getSquare(27),board.getSquare(44),board)==true);

    }
BOOST_AUTO_TEST_SUITE_END()