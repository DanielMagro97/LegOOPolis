#pragma once

#include "../Building.h"

class TwoStoreyHouse : public Building{

private:
    static const int bricksNeeded = 20;
    static const int doorsNeeded = 1;
    static const int windowsNeeded = 3;
    static const BuildingType buildingType = BuildingType::twostoreyhouse;

public:
    TwoStoreyHouse():Building(TwoStoreyHouse::bricksNeeded, TwoStoreyHouse::doorsNeeded,
                              TwoStoreyHouse::windowsNeeded, TwoStoreyHouse::buildingType){}

};