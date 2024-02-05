#include "DigitalCallOption.h"

//Constructeur
DigitalCallOption::DigitalCallOption(double expiry, double strike) : DigitalOption(expiry, strike) {}

//Destructeur
DigitalCallOption::~DigitalCallOption() {
}

//Methode 
	//Calcul du payoff
double DigitalCallOption::payoff(double z) {

	if (z >= GetDigitalStrike())
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

	//Recuperation du type de l'option
OptionType DigitalCallOption::GetOptionType() {

	return OptionType::Call;
}