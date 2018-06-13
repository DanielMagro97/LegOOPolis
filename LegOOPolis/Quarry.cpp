#include "Quarry.h"

void Quarry::fillQuarry(PieceType pieceType, int amount) {
    for (int i = 0; i < amount; i++) {
        LegoPiece legoPiece(pieceType);
        this->quarry->insertAtEnd(legoPiece);
    }
}
