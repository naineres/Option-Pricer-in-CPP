#pragma once
#include <vector>
#include "AsianOption.h"
#include "VanillaOption.h" //Pour le option type


class AsianPutOption : public AsianOption
{
public:
    //Constructeur
    AsianPutOption(std::vector<double>, double);

    //Methode
    double payoff(double);
    OptionType GetOptionType();
    double GetStrike();
private:
    //Attribut
    double _strike;

};


