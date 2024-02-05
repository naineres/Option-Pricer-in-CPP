#pragma once
#include "VanillaOption.h"

class PutOption : public VanillaOption
{
public:
    //Constructeur
    PutOption(double e, double s) : VanillaOption(e, s) {};

    //Methodes
    double payoff(double z);
    OptionType GetOptionType();
};

