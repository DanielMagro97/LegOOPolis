#pragma once

#include "LinkedList.h"
#include "Building.h"

class City {

public:
    LinkedList<Building *> *city ;

    City(){
        city = new LinkedList<Building *>;
    }

    int numberOfBuildingsInCity(BuildingType buildingType);
};
