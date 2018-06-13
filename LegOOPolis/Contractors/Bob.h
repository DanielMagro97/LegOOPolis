#pragma once

#include "../Builders/OneStoreyHouseBuilder.h"
#include "../Builders/TwoStoreyHouseBuilder.h"

class Bob: public OneStoreyHouseBuilder, public TwoStoreyHouseBuilder{

private:
    static const ContractorName name = ContractorName::bob;

public:
    Bob() : Builder(Bob::name), OneStoreyHouseBuilder(Bob::name), TwoStoreyHouseBuilder(Bob::name) {}
};
