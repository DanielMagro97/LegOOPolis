#pragma once

#include "../Builder.h"
#include "../Building.h"
#include "../Quarry.h"

class ChurchBuilder: virtual public Builder{

public:
    ChurchBuilder(ContractorName name):Builder(name){}

    Building *buildChurch(Quarry *quarry);
};
