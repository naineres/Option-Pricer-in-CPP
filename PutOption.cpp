#include "PutOption.h"

//Methodes
    //Calcul payoff
double PutOption::payoff(double z) {
    if (z <= getStrike())
    {
        return getStrike() - z;
    }
    else { return 0; }
}

    //Recuperation du type de l'option
OptionType PutOption::GetOptionType() {
    return OptionType::Put;
}