#include "AmericanCallOption.h"
#include <iostream>


//Constructeur 
AmericanCallOption::AmericanCallOption(double strike, double expiry) : AmericanOption(strike, expiry){}

//Methode
	//Obtention du Payoff
double AmericanCallOption::payoff(double z)
{
	if (z >= GetStrike())
	{
		return z - GetStrike();
	}
	else
	{
		return 0;
	}
}

	//Obtention du type de l'option
OptionType AmericanCallOption::GetOptionType()
{
	return OptionType::Call;
}