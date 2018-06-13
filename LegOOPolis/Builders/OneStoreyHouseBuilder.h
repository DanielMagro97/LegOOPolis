#pragma once

#include "../Builder.h"
#include "../Buildings/OneStoreyHouse.h"
#include "../Quarry.h"

class OneStoreyHouseBuilder: virtual public Builder {

public:
    OneStoreyHouseBuilder(ContractorName name):Builder(name){}

    Building *buildOneStoreyHouse(Quarry *quarry);
        // deduct pieces
        // check if enough
        // return address to Building linked List

};
