//
// Created by student on 05.07.2021.
//

#include <boost/test/unit_test.hpp>
#include "typedefs.h"
#include "model/Game.h"
#include "model/Board.h"
#include "model/Square.h"
#include "model/Player.h"
#include "model/Interface.h"
using namespace std;
struct GameFixture
{shared_ptr<Game>Test;
    shared_ptr<Player> P1;
    shared_ptr<Player> P2;
    shared_ptr<Interface>ITest;
    GameFixture()
    {
        P1 = make_shared<Player>(0);
        P2 = make_shared<Player>(1);
        Test=make_shared<Game>(P1,P2);
    }
};
BOOST_FIXTURE_TEST_SUITE(TestSuiteGame,GameFixture)
    BOOST_AUTO_TEST_CASE(GameResultTest) {
    BOOST_TEST(Test->isResult()==false);
    Test->setResult(false);
        BOOST_TEST(Test->isResult()==true);
    }
    BOOST_AUTO_TEST_CASE(GameLoadTest) {
        BOOST_TEST(Test->isLoad()==false);
        Test->setIsLoad(false);
        BOOST_TEST(Test->isLoad()==true);
    }
    BOOST_AUTO_TEST_CASE(GameTimeTest) {
    int t=900;
        Test->setTime(t);
        BOOST_TEST(Test->getTime()==900);
    }
BOOST_AUTO_TEST_SUITE_END();