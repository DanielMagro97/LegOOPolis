#pragma once

#include <iostream>

enum ContractorName {
    bob,
    peter,
    jane
};

using namespace std;

class Builder {

private:
    ContractorName name;

public:
    Builder(ContractorName name){
        this->name = name;
    }

    ContractorName getName(){
        return name;
    }
};
