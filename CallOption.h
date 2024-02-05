#pragma once
#include "VanillaOption.h"

class CallOption : public VanillaOption {
public:
    //Constructeur
    CallOption(double e, double s) : VanillaOption(e, s){};

    //Methodes
    double payoff(double z);
    OptionType GetOptionType();
};

