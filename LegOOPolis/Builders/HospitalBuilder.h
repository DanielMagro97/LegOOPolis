#pragma once

#include "../Builder.h"
#include "../Building.h"
#include "../Quarry.h"

class HospitalBuilder: virtual public Builder{

public:
    HospitalBuilder(ContractorName name):Builder(name){}

    Building *buildHospital(Quarry *quarry);
};
