#include "AmericanPutOption.h"
#include <vector>


//Constructeur
AmericanPutOption::AmericanPutOption(double strike, double expiry) : AmericanOption(strike, expiry){}

//Methodes
	//Calcul du Payoff
double AmericanPutOption::payoff(double z)
{
	if (z <= GetStrike())
	{
		return GetStrike() - z;
	}
	else
	{
		return 0;
	}
}

	//Obtention du type de l'option
OptionType AmericanPutOption::GetOptionType()
{
	return OptionType::Put;
}