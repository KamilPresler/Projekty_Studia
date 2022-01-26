//
// Created by student on 04.07.2021.
//

#ifndef COMPUTERINTERFACE_H
#define COMPUTERINTERFACE_H
#include "typedefs.h"
#include "Interface.h"

class ComputerInterface :public Interface{
public:
    ComputerInterface();

    virtual ~ComputerInterface();

    int selectStartSquare()override;
    int selectEndSquare()override;
};


#endif //COMPUTERINTERFACE_H
