//
// Created by student on 04.07.2021.
//

#include "model/ComputerInterface.h"
#include <time.h>
#include <cstdlib>
#include <iostream>

using namespace std;
ComputerInterface::ComputerInterface() {}

ComputerInterface::~ComputerInterface() {

}

int ComputerInterface::selectStartSquare() {
    srand(time(NULL));
    int row=rand()%8+1;
    int column=rand()%8+1;
    return row*10+column;
}

int ComputerInterface::selectEndSquare() {
cout<<"Komputer Mysli"<<endl;
return 0;
}
