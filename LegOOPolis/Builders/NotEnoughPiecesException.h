#pragma once

#include <iostream>
#include <exception>

using namespace std;

class NotEnoughPiecesException: public exception {

    virtual const char* what() const throw() {
        return "Not enough Lego Pieces in the Quarry to build the desired Building. Moving on to the next";
    }
};

