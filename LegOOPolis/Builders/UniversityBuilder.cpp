#include "../Buildings/University.h"
#include "UniversityBuilder.h"
#include "NotEnoughPiecesException.h"

Building* UniversityBuilder::buildUniversity(Quarry *quarry) {

    Building *building = new University();

    LegoPiece brick(PieceType::brick);
    LegoPiece door(PieceType::door);
    LegoPiece window(PieceType::window);

    // Deducting the required bricks from the quarry
    for (int i = 0; i < building->getBricksNeeded(); i++) {
        if (quarry->quarry->nodeExists(brick)) {
            int index = quarry->quarry->nodeIndex(brick);
            quarry->quarry->deleteNodeAtIndex(index);
        } else {
            std::cout << "Not enough bricks in the quarry" << endl;
            delete(building);
            throw NotEnoughPiecesException();
        }
    }

    // Deducting the required doors from the quarry
    for (int i = 0; i < building->getDoorsNeeded(); i++) {
        if (quarry->quarry->nodeExists(door)) {
            int index = quarry->quarry->nodeIndex(door);
            quarry->quarry->deleteNodeAtIndex(index);
        } else {
            std::cout << "Not enough doors in the quarry" << endl;
            delete(building);
            throw NotEnoughPiecesException();
        }
    }

    // Deducting the required windows from the quarry
    for (int i = 0; i < building->getWindowsNeeded(); i++) {
        if (quarry->quarry->nodeExists(window)) {
            int index = quarry->quarry->nodeIndex(window);
            quarry->quarry->deleteNodeAtIndex(index);
        } else {
            std::cout << "Not enough windows in the quarry" << endl;
            delete(building);
            throw NotEnoughPiecesException();
        }
    }

    return building;
}