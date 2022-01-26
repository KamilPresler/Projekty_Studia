//
// Created by student on 04.07.2021.
//
#include <boost/test/unit_test.hpp>
#include "typedefs.h"
#include "model/Piece.h"
#include "model/Board.h"
#include "model/Square.h"
using namespace std;
struct BoardFixture
{shared_ptr<Board>Test;

    BoardFixture()
    {
    Test=make_shared<Board>();
    }
};
BOOST_FIXTURE_TEST_SUITE(TestSuiteBoard,BoardFixture)
BOOST_AUTO_TEST_CASE(BoardGetSquareTest) {
        BOOST_TEST(Test->getSquare(0)->getNr()==0);
         BOOST_TEST(Test->getSquare(5)->getNr()==5);
        BOOST_TEST(Test->getSquare(35)->getNr()==35);
        BOOST_TEST(Test->getSquare(63)->getNr()==63);
}
    BOOST_AUTO_TEST_CASE(BoardSetStartPiecesTest) {
    Test->setStartPieces();
        BOOST_TEST(Test->getSquare(8)->getPiece()!=nullptr);
        BOOST_TEST(Test->getSquare(8)->getPiece()->getType()==Piece::Pawn);
        BOOST_TEST(Test->getSquare(8)->getPiece()->isColor()==0);
        BOOST_TEST(Test->getSquare(9)->getPiece()->getType()==Piece::Pawn);
        BOOST_TEST(Test->getSquare(9)->getPiece()->isColor()==0);
        BOOST_TEST(Test->getSquare(10)->getPiece()->getType()==Piece::Pawn);
        BOOST_TEST(Test->getSquare(10)->getPiece()->isColor()==0);
        BOOST_TEST(Test->getSquare(11)->getPiece()->getType()==Piece::Pawn);
        BOOST_TEST(Test->getSquare(11)->getPiece()->isColor()==0);
        BOOST_TEST(Test->getSquare(12)->getPiece()->getType()==Piece::Pawn);
        BOOST_TEST(Test->getSquare(12)->getPiece()->isColor()==0);
        BOOST_TEST(Test->getSquare(13)->getPiece()->getType()==Piece::Pawn);
        BOOST_TEST(Test->getSquare(13)->getPiece()->isColor()==0);
        BOOST_TEST(Test->getSquare(14)->getPiece()->getType()==Piece::Pawn);
        BOOST_TEST(Test->getSquare(14)->getPiece()->isColor()==0);
        BOOST_TEST(Test->getSquare(15)->getPiece()->getType()==Piece::Pawn);
        BOOST_TEST(Test->getSquare(15)->getPiece()->isColor()==0);
        BOOST_TEST(Test->getSquare(48)->getPiece()->getType()==Piece::Pawn);
        BOOST_TEST(Test->getSquare(48)->getPiece()->isColor()==1);
        BOOST_TEST(Test->getSquare(49)->getPiece()->getType()==Piece::Pawn);
        BOOST_TEST(Test->getSquare(49)->getPiece()->isColor()==1);
        BOOST_TEST(Test->getSquare(50)->getPiece()->getType()==Piece::Pawn);
        BOOST_TEST(Test->getSquare(50)->getPiece()->isColor()==1);
        BOOST_TEST(Test->getSquare(51)->getPiece()->getType()==Piece::Pawn);
        BOOST_TEST(Test->getSquare(51)->getPiece()->isColor()==1);
        BOOST_TEST(Test->getSquare(52)->getPiece()->getType()==Piece::Pawn);
        BOOST_TEST(Test->getSquare(52)->getPiece()->isColor()==1);
        BOOST_TEST(Test->getSquare(53)->getPiece()->getType()==Piece::Pawn);
        BOOST_TEST(Test->getSquare(53)->getPiece()->isColor()==1);
        BOOST_TEST(Test->getSquare(54)->getPiece()->getType()==Piece::Pawn);
        BOOST_TEST(Test->getSquare(54)->getPiece()->isColor()==1);
        BOOST_TEST(Test->getSquare(55)->getPiece()->getType()==Piece::Pawn);
        BOOST_TEST(Test->getSquare(55)->getPiece()->isColor()==1);
        BOOST_TEST(Test->getSquare(0)->getPiece()->getType()==Piece::Rook);
        BOOST_TEST(Test->getSquare(0)->getPiece()->isColor()==0);
        BOOST_TEST(Test->getSquare(7)->getPiece()->getType()==Piece::Rook);
        BOOST_TEST(Test->getSquare(7)->getPiece()->isColor()==0);
        BOOST_TEST(Test->getSquare(56)->getPiece()->getType()==Piece::Rook);
        BOOST_TEST(Test->getSquare(56)->getPiece()->isColor()==1);
        BOOST_TEST(Test->getSquare(63)->getPiece()->getType()==Piece::Rook);
        BOOST_TEST(Test->getSquare(63)->getPiece()->isColor()==1);
        BOOST_TEST(Test->getSquare(1)->getPiece()->getType()==Piece::Knight);
        BOOST_TEST(Test->getSquare(1)->getPiece()->isColor()==0);
        BOOST_TEST(Test->getSquare(6)->getPiece()->getType()==Piece::Knight);
        BOOST_TEST(Test->getSquare(6)->getPiece()->isColor()==0);
        BOOST_TEST(Test->getSquare(57)->getPiece()->getType()==Piece::Knight);
        BOOST_TEST(Test->getSquare(57)->getPiece()->isColor()==1);
        BOOST_TEST(Test->getSquare(62)->getPiece()->getType()==Piece::Knight);
        BOOST_TEST(Test->getSquare(62)->getPiece()->isColor()==1);
        BOOST_TEST(Test->getSquare(2)->getPiece()->getType()==Piece::Bishop);
        BOOST_TEST(Test->getSquare(2)->getPiece()->isColor()==0);
        BOOST_TEST(Test->getSquare(5)->getPiece()->getType()==Piece::Bishop);
        BOOST_TEST(Test->getSquare(5)->getPiece()->isColor()==0);
        BOOST_TEST(Test->getSquare(58)->getPiece()->getType()==Piece::Bishop);
        BOOST_TEST(Test->getSquare(58)->getPiece()->isColor()==1);
        BOOST_TEST(Test->getSquare(61)->getPiece()->getType()==Piece::Bishop);
        BOOST_TEST(Test->getSquare(61)->getPiece()->isColor()==1);
        BOOST_TEST(Test->getSquare(4)->getPiece()->getType()==Piece::King);
        BOOST_TEST(Test->getSquare(4)->getPiece()->isColor()==0);
        BOOST_TEST(Test->getSquare(60)->getPiece()->getType()==Piece::King);
        BOOST_TEST(Test->getSquare(60)->getPiece()->isColor()==1);
        BOOST_TEST(Test->getSquare(3)->getPiece()->getType()==Piece::Queen);
        BOOST_TEST(Test->getSquare(3)->getPiece()->isColor()==0);
        BOOST_TEST(Test->getSquare(59)->getPiece()->getType()==Piece::Queen);
        BOOST_TEST(Test->getSquare(59)->getPiece()->isColor()==1);
        BOOST_TEST(Test->getSquare(25)->getPiece()==nullptr);
        BOOST_TEST(Test->getSquare(45)->getPiece()==nullptr);
    }
BOOST_AUTO_TEST_SUITE_END()