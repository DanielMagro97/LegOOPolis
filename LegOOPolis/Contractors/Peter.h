#pragma once

#include "../Builders/ChurchBuilder.h"

class Peter: public ChurchBuilder{

private:
    static const ContractorName name = ContractorName::peter;

public:
    Peter() : Builder(Peter::name), ChurchBuilder(Peter::name) {}
};
