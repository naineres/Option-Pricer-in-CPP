#pragma once
#include "AsianOption.h"
#include "VanillaOption.h" // Pour le OptionType


class AsianCallOption :
    public AsianOption
{
public:
    //Constructeur
    AsianCallOption(std::vector<double>, double);

    //Methodes
    double payoff(double);
    OptionType GetOptionType();
    double GetStrike();

private:
    //Attribut
    double _strike;
};
