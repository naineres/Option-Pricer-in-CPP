#pragma once
#include "DigitalPutOption.h"

//Constructeurs
DigitalPutOption::DigitalPutOption(double expiry, double strike) : DigitalOption(expiry, strike) {}

//Destructeur
DigitalPutOption::~DigitalPutOption() {}

//Methode
	//Calcul du Payoff
double DigitalPutOption::payoff(double z) {
	if (z >= GetDigitalStrike())
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

	//Recuperation du type de l'option
OptionType DigitalPutOption::GetOptionType() {

	return OptionType::Put;
}