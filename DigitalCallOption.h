#pragma once
#include "DigitalOption.h"
# include "VanillaOption.h"

class DigitalCallOption :
    public DigitalOption
{
public:
	//Constructeurs
	DigitalCallOption(double, double);

	//Destructeurs
	~DigitalCallOption();

	//M�thodes
	double payoff(double other);
	OptionType GetOptionType();
};

