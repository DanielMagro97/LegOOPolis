#pragma once

#include "LegoPiece.h"
#include "LinkedList.h"

class Quarry {

public:
    LinkedList<LegoPiece> *quarry ;

    Quarry(){
        quarry = new LinkedList<LegoPiece>;
    }

    void fillQuarry(PieceType pieceType, int amount);
};
