#include "DigitalOption.h"

//Constructeur
DigitalOption::DigitalOption(double expiry, double strike) : Option(expiry)
{
	if (strike > 0)
	{
		_digitalstrike = strike;
	}
	else
	{
		_digitalstrike = 0;
	}
}

//Destructeur 
DigitalOption::~DigitalOption() {
}

//Methodes
	//Recuperation du strike digital
double DigitalOption::GetDigitalStrike() { return _digitalstrike; }

	//Recuperation de la date de maturité
double DigitalOption::GetExpiry() { return Option::GetExpiry(); }
