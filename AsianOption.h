#pragma once
#include "Option.h"
#include <vector>


class AsianOption :public Option
{
public:
	//Constructeur
	AsianOption(std::vector<double>);

	//Methode
	std::vector<double> GetTimeSteps();
	double payoffPath(std::vector<double>);
	bool isAsianOption();

private:
	//Attribut
	std::vector<double> _TimeSteps;
};
