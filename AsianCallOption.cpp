#include "AsianCallOption.h"

//Constructeurs
AsianCallOption::AsianCallOption(std::vector<double> TimeSteps, double strike) : AsianOption(TimeSteps)
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
	//Calcul du Payoff
double AsianCallOption::payoff(double z) //avec z, la moyenne des prix du sous-jacents
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

	//Obtention du type de l'obtion
OptionType AsianCallOption::GetOptionType()
{
	return OptionType::Call;
}
	
	//Recuperation du Strike
double AsianCallOption::GetStrike()
{
	return _strike;
}