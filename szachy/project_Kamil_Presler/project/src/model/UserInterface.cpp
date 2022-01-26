//
// Created by student on 04.07.2021.
//

#include "model/UserInterface.h"
#include <iostream>

#include <exceptions/SquareExceptions.h>

using namespace std;
int UserInterface::selectStartSquare() {
    string str;
       cout << endl << "Podaj pole startowe: " << endl;
    cin.sync();
       getline(cin,str);
       int s=stoi(str);
       if((s>=11&&s<=18)||(s>=21&&s<=28)||(s>=31&&s<=38)||(s>=41&&s<=48)||(s>=51&&s<=58)||(s>=61&&s<=68)||(s>=71&&s<=78)||(s>=81&&s<=88))
     return s;
       else throw SquareException("Podano zle pole startowe");
}
int UserInterface::selectEndSquare() {
    string str;
    cout<<"Podaj pole koncowe: "<<endl;
    cin.sync();
    getline(cin,str);
    int e=stoi(str);
    if((e>=11&&e<=18)||(e>=21&&e<=28)||(e>=31&&e<=38)||(e>=41&&e<=48)||(e>=51&&e<=58)||(e>=61&&e<=68)||(e>=71&&e<=78)||(e>=81&&e<=88))
        return e;
    else throw SquareException("Podano zle pole koncowe");
}
void UserInterface::error() {
    cout<<"Podano zly ruch.Sprobuj jeszcze raz"<<endl;
}

UserInterface::UserInterface() {}

UserInterface::~UserInterface() {

}
