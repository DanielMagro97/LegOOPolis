#pragma once

#include "../Building.h"

class Church : public Building{

private:
    static const int bricksNeeded = 40;
    static const int doorsNeeded = 3;
    static const int windowsNeeded = 10;
    static const BuildingType buildingType = BuildingType::church;

public:
    Church():Building(Church::bricksNeeded, Church::doorsNeeded,
                      Church::windowsNeeded, Church::buildingType){}
};
