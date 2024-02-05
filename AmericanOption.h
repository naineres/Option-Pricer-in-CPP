#pragma once
#include "Option.h" 
#include <vector>

class AmericanOption : public Option
{
public:
	//Constructeur
	AmericanOption(double, double);

	//Methodes
	double GetExpiry();
	double GetStrike();
	bool isAmericanOption();

private:
	//Attribut
	double _strike;
};