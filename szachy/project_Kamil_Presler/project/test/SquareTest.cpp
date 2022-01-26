//
// Created by student on 04.07.2021.
//

#include <boost/test/unit_test.hpp>
#include "typedefs.h"
#include "model/Piece.h"
#include "model/Square.h"
#include "model/Bishop.h"
using namespace std;
struct SquareFixture
{shared_ptr<Square>Test;
    shared_ptr<Bishop>B;
    SquareFixture()
    {
        Test=make_shared<Square>(15);
        B=make_shared<Bishop>(Piece::Bishop,1);
    }
};
BOOST_FIXTURE_TEST_SUITE(TestSuiteSquare,SquareFixture)
BOOST_AUTO_TEST_CASE(SquareGetNrTest) {
    BOOST_TEST(Test->getNr()==15);
}
    BOOST_AUTO_TEST_CASE(SquareGetPieceTest) {
        BOOST_TEST(Test->getPiece()==nullptr);

    }
    BOOST_AUTO_TEST_CASE(SquareSetPieceTest) {
        Test->setPiece(B);
        BOOST_TEST(Test->getPiece()!=nullptr);
    }
    BOOST_AUTO_TEST_CASE(SquareResetPieceTest) {
        Test->resetPiece();
        BOOST_TEST(Test->getPiece()==nullptr);
    }

BOOST_AUTO_TEST_SUITE_END()