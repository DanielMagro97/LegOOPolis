#include "City.h"

int City::numberOfBuildingsInCity(BuildingType buildingType) {
    int count = 0;

    for (int i = 0; i < city->getSize(); i++) {
        if (city->getNodeAtIndex(i).data->getBuildingType() == buildingType){
            count++;
        }
    }

    return count;
}