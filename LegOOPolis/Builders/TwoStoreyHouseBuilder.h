#pragma once

#include "../Builder.h"
#include "../Building.h"
#include "../Quarry.h"

class TwoStoreyHouseBuilder: virtual public Builder{

public:
    TwoStoreyHouseBuilder(ContractorName name):Builder(name){}

    Building *buildTwoStoreyHouse(Quarry *quarry);
};
