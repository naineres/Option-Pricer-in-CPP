#include "CallOption.h"



//Calcul du payoff
double CallOption::payoff(double z) {
    if (z >= getStrike())
    {
        return z - getStrike();
    }
    else { return 0; }
};

//Recuperation du type de l'option
OptionType CallOption::GetOptionType() {
    return OptionType::Call;
}