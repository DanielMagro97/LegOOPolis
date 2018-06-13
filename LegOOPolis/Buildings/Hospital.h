#pragma once

#include "../Building.h"

class Hospital : public Building{

private:
    static const int bricksNeeded = 60;
    static const int doorsNeeded = 10;
    static const int windowsNeeded = 15;
    static const BuildingType buildingType = BuildingType::hospital;

public:
    Hospital():Building(Hospital::bricksNeeded, Hospital::doorsNeeded,
                        Hospital::windowsNeeded, Hospital::buildingType){}
};
