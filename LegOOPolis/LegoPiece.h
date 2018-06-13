#pragma once

#include <iostream>

using namespace std;


enum PieceType {
    brick,
    door,
    window
};


class LegoPiece {

private:
    PieceType pieceType;

public:
    // Default Constructor
    LegoPiece(){
        this->pieceType = PieceType::brick;
    }

    LegoPiece(PieceType pieceType){
        this->pieceType = pieceType;
    }

    PieceType getPieceType() const {
        return pieceType;
    }

    // == Operator Overload for comparing the PieceType of LegoPieces
    bool operator==(const LegoPiece &rhs) {
        return pieceType == rhs.pieceType;
    }

};
