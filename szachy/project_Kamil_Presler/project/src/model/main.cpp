#include <iostream>
#include "model/Game.h"
#include "model/Player.h"
#include "typedefs.h"
#include "model/Interface.h"
using namespace std;


int main(){
    PlayerPtr P1(new Player(0));
    PlayerPtr P2(new Player(1));
GamePtr g(new Game(P1,P2));


g->play();

}

