//
// Created by student on 04.07.2021.
//
#include <boost/test/unit_test.hpp>
#include "typedefs.h"
#include "model/UserInterface.h"
#include "model/Interface.h"

#include "model/Board.h"
using namespace std;
struct InterfaceFixture
{shared_ptr<Interface>Test;
shared_ptr<Board>Gameboard;

    InterfaceFixture()
    {
        Test=make_shared<UserInterface>();
        Gameboard=make_shared<Board>();
    }
};
BOOST_FIXTURE_TEST_SUITE(TestSuiteInterface,InterfaceFixture)
    BOOST_AUTO_TEST_CASE(InterfaceConvertToSquareTest)
    {
   BOOST_TEST(Gameboard->getSquare(Test->convertToSquare(11))->getNr()==0);
   BOOST_TEST(Gameboard->getSquare(Test->convertToSquare(88))->getNr()==63);
   BOOST_TEST(Gameboard->getSquare(Test->convertToSquare(42))->getNr()==25);

    }
    BOOST_AUTO_TEST_CASE(InterfaceDrawPiecesTest)
    { Gameboard->setStartPieces();
        BOOST_TEST(Test->drawPieces(Gameboard->getSquare(8))=="WP");
        BOOST_TEST(Test->drawPieces(Gameboard->getSquare(9))=="WP");
        BOOST_TEST(Test->drawPieces(Gameboard->getSquare(10))=="WP");
        BOOST_TEST(Test->drawPieces(Gameboard->getSquare(11))=="WP");
        BOOST_TEST(Test->drawPieces(Gameboard->getSquare(12))=="WP");
        BOOST_TEST(Test->drawPieces(Gameboard->getSquare(13))=="WP");
        BOOST_TEST(Test->drawPieces(Gameboard->getSquare(14))=="WP");
        BOOST_TEST(Test->drawPieces(Gameboard->getSquare(15))=="WP");
        BOOST_TEST(Test->drawPieces(Gameboard->getSquare(0))=="WR");
        BOOST_TEST(Test->drawPieces(Gameboard->getSquare(1))=="WN");
        BOOST_TEST(Test->drawPieces(Gameboard->getSquare(2))=="WB");
        BOOST_TEST(Test->drawPieces(Gameboard->getSquare(3))=="WQ");
        BOOST_TEST(Test->drawPieces(Gameboard->getSquare(4))=="WK");
        BOOST_TEST(Test->drawPieces(Gameboard->getSquare(5))=="WB");
        BOOST_TEST(Test->drawPieces(Gameboard->getSquare(6))=="WN");
        BOOST_TEST(Test->drawPieces(Gameboard->getSquare(7))=="WR");

        BOOST_TEST(Test->drawPieces(Gameboard->getSquare(48))=="BP");
        BOOST_TEST(Test->drawPieces(Gameboard->getSquare(49))=="BP");
        BOOST_TEST(Test->drawPieces(Gameboard->getSquare(50))=="BP");
        BOOST_TEST(Test->drawPieces(Gameboard->getSquare(51))=="BP");
        BOOST_TEST(Test->drawPieces(Gameboard->getSquare(52))=="BP");
        BOOST_TEST(Test->drawPieces(Gameboard->getSquare(53))=="BP");
        BOOST_TEST(Test->drawPieces(Gameboard->getSquare(54))=="BP");
        BOOST_TEST(Test->drawPieces(Gameboard->getSquare(55))=="BP");
        BOOST_TEST(Test->drawPieces(Gameboard->getSquare(56))=="BR");
        BOOST_TEST(Test->drawPieces(Gameboard->getSquare(57))=="BN");
        BOOST_TEST(Test->drawPieces(Gameboard->getSquare(58))=="BB");
        BOOST_TEST(Test->drawPieces(Gameboard->getSquare(59))=="BQ");
        BOOST_TEST(Test->drawPieces(Gameboard->getSquare(60))=="BK");
        BOOST_TEST(Test->drawPieces(Gameboard->getSquare(61))=="BB");
        BOOST_TEST(Test->drawPieces(Gameboard->getSquare(62))=="BN");
        BOOST_TEST(Test->drawPieces(Gameboard->getSquare(63))=="BR");
    }
BOOST_AUTO_TEST_SUITE_END();
