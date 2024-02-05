#include "AmericanOption.h"


//Constructeur
AmericanOption::AmericanOption(double expiry, double strike) : Option(expiry)
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
	//Obtention du Strike
double AmericanOption::GetStrike()
{
	return _strike;
}

	//Otention de la Maturité
double AmericanOption::GetExpiry()
{
	return Option::GetExpiry();

}

	//Obtention d'un bool en fonction du type de l'option
bool AmericanOption::isAmericanOption()
{
	return true;
}



