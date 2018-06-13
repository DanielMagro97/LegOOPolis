#pragma once

#include "../Building.h"

class OneStoreyHouse : public Building{

private:
    static const int bricksNeeded = 10;
    static const int doorsNeeded = 1;
    static const int windowsNeeded = 1;
    static const BuildingType buildingType = BuildingType::onestoreyhouse;

public:
    OneStoreyHouse():Building(OneStoreyHouse::bricksNeeded, OneStoreyHouse::doorsNeeded,
                              OneStoreyHouse::windowsNeeded, OneStoreyHouse::buildingType){}
};
