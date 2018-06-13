#pragma once

#include "../Builders/HospitalBuilder.h"
#include "../Builders/UniversityBuilder.h"

class Jane: public HospitalBuilder, public UniversityBuilder{

private:
    static const ContractorName name = ContractorName::jane;

public:
    Jane() : Builder(Jane::name), HospitalBuilder(Jane::name), UniversityBuilder(Jane::name) {}
};
