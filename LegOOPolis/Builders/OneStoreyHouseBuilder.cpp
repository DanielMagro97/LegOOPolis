#include "../Buildings//OneStoreyHouse.h"
#include "OneStoreyHouseBuilder.h"
#include "NotEnoughPiecesException.h"

Building* OneStoreyHouseBuilder::buildOneStoreyHouse(Quarry *quarry) {

    Building *building = new OneStoreyHouse();

    LegoPiece brick(PieceType::brick);
    LegoPiece door(PieceType::door);
    LegoPiece window(PieceType::window);

    // Deducting the required bricks from the quarry
    for (int i = 0; i < building->getBricksNeeded(); i++) {
        // if the quarry contains a brick
        if (quarry->quarry->nodeExists(brick)) {
            // find the index of that brick
            int index = quarry->quarry->nodeIndex(brick);
            // and delete that brick from the quarry
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