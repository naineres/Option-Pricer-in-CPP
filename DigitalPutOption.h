#pragma once
#include "DigitalOption.h"
#include "VanillaOption.h"

class DigitalPutOption :
    public DigitalOption
{
public:
	//Constructeurs
	DigitalPutOption(double, double);

	//Destructeurs
	~DigitalPutOption();

	//M�thodes
	double payoff(double other);
	OptionType GetOptionType();
};

