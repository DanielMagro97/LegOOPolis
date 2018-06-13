#pragma once

#include "../Building.h"

class University : public Building{

private:
    static const int bricksNeeded = 80;
    static const int doorsNeeded = 10;
    static const int windowsNeeded = 20;
    static const BuildingType buildingType = BuildingType::university;

public:
    University():Building(University::bricksNeeded, University::doorsNeeded,
                          University::windowsNeeded, University::buildingType){}
};
