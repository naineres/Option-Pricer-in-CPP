#pragma once
#include "AmericanOption.h" // Classe m�re
#include "VanillaOption.h" //Optiontype file
#include <vector>

class AmericanCallOption : public AmericanOption
{
    public:
        //Constructeur
        AmericanCallOption(double, double);

        //Methode
        double payoff(double);
        OptionType GetOptionType();
};


