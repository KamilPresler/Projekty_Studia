//
// Created by student on 04.07.2021.
//

#ifndef USERINTERFACE_H
#define USERINTERFACE_H
#include "typedefs.h"
#include "model/Interface.h"

class UserInterface: public Interface {
public:
    UserInterface();

    virtual ~UserInterface();

    void error();
    int selectStartSquare()override;
 int selectEndSquare()override;
};


#endif //USERINTERFACE_H
