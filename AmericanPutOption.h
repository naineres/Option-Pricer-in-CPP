#pragma once
#include <vector>
#include "AmericanOption.h" 
#include "VanillaOption.h" //Pour le OptionType

class AmericanPutOption : public AmericanOption
{
public:
    //Constructeur
    AmericanPutOption(double, double);

    //Methodes
    double payoff(double);
    OptionType GetOptionType();

};