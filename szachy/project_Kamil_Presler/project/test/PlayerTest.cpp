//
// Created by student on 04.07.2021.
//
#include <boost/test/unit_test.hpp>
#include "typedefs.h"
#include "model/Player.h"
#include <string>
using namespace std;
struct PlayerFixture {
    shared_ptr<Player> P1Test;
    shared_ptr<Player> P2Test;

    PlayerFixture() {
        P1Test = make_shared<Player>(0);
        P2Test = make_shared<Player>(1);
    }
};
    BOOST_FIXTURE_TEST_SUITE(TestSuitePlayer,PlayerFixture)
    BOOST_AUTO_TEST_CASE(PlayerIsPieceColorTest) {
        BOOST_TEST(P1Test->isPieceColor()==0);
            BOOST_TEST(P2Test->isPieceColor()==1);
    }
        BOOST_AUTO_TEST_CASE(PlayerSetAndGetNameTest) {
        string name ="aaa";
        P1Test->setName(name);
        BOOST_TEST(P1Test->getName()==name);
        }
        BOOST_AUTO_TEST_CASE(PlayerIsPlayerTypeTest) {
            BOOST_TEST(P1Test->isPlayerType()==0);}

        BOOST_AUTO_TEST_CASE(PlayerSetPlayerTypeTest) {
            P1Test->setPlayerType(!P1Test->isPlayerType());
            BOOST_TEST(P1Test->isPlayerType()==1); }


    BOOST_AUTO_TEST_SUITE_END();