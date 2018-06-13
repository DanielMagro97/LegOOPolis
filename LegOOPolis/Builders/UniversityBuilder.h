#pragma once

#include "../Builder.h"
#include "../Building.h"
#include "../Quarry.h"

class UniversityBuilder: virtual public Builder{

public:
    UniversityBuilder(ContractorName name):Builder(name){}

    Building *buildUniversity(Quarry *quarry);
};
