#include "AsianPutOption.h"

//Constructeur
AsianPutOption::AsianPutOption(std::vector<double> TimeSteps, double strike) : AsianOption(TimeSteps)
{
	if (strike > 0)
	{
		_strike = strike;
	}
	else
	{
		_strike = 0;
	}
}

//Methodes
	//Récuperation du Payoff 
double AsianPutOption::payoff(double z) // avec Z la moyenne des prix des sous-jacents
{
	if (z < GetStrike())
	{
		return GetStrike() - z;
	}
	else
	{
		return 0;
	}
}

	//Obtention du type de l'option
OptionType AsianPutOption::GetOptionType()
{
	return OptionType::Put;
}

	//Recuperation du Strike
double AsianPutOption::GetStrike()
{
	return _strike;
}