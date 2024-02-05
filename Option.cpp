#include "Option.h"

//Constructeur 
Option::Option(double expiry)
{
	if (expiry > 0) { _expiry = expiry; }
	else
	{
		_expiry = 0;
	}
}

//Methode
	//Recuperation de la date de maturité
double Option::GetExpiry()
{
	return _expiry;
}

	//Verification du type asiatique de l'option
bool Option::isAsianOption()
{
	return false;
}

	//Verification du type americain de l'option
bool Option::isAmericanOption()
{
	return false;
}

	//Calcul du Payoff
double Option::payoffPath(std::vector<double> spot_prices)//vecteur de spot price
{
	return payoff(spot_prices[spot_prices.size() - 1]);
}