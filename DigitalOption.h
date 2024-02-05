#pragma once
#include "Option.h"
#include "VanillaOption.h"



class DigitalOption :
    public Option
{
public:
	//Constructeur
	DigitalOption(double, double);

	//Destructeur
	~DigitalOption();

	//Methodes
	double GetDigitalStrike();
	double GetExpiry();
	virtual OptionType GetOptionType() = 0;
	friend class BlackScholesPricer;

private:
	//Attributs 
	double _digitalstrike;
};

