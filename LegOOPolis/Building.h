#pragma once

#include <iostream>

using namespace std;

enum BuildingType{
    onestoreyhouse,
    twostoreyhouse,
    church,
    hospital,
    university
};

class Building {

protected:
    int bricksNeeded;
    int doorsNeeded;
    int windowsNeeded;
    BuildingType buildingType;

public:
    Building (int bricksNeeded, int doorsNeeded, int windowsNeeded, BuildingType buildingType){
        this->bricksNeeded = bricksNeeded;
        this->doorsNeeded = doorsNeeded;
        this->windowsNeeded = windowsNeeded;
        this->buildingType = buildingType;
    }

    int getBricksNeeded(){
        return bricksNeeded;
    }
    int getDoorsNeeded(){
        return doorsNeeded;
    }
    int getWindowsNeeded(){
        return windowsNeeded;
    }
    BuildingType getBuildingType(){
        return buildingType;
    }

};
