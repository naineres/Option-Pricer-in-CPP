#include "AsianOption.h"

//Constructeur
AsianOption::AsianOption(std::vector<double> TimeSteps) : Option(TimeSteps[TimeSteps.size() - 1])
{
	_TimeSteps = TimeSteps;
}

//Methodes
	//Recuperation du timesteps
std::vector<double> AsianOption::GetTimeSteps()
{
	return _TimeSteps;
}

	//Recuperation du payoff
double AsianOption::payoffPath(std::vector<double> v) //v est un vecteur avec les sous-jacents
{
	double z = 0;
	double m = v.size();
	for (int i = 0; i < m; i++)
	{
		z = z + v[i];
		std::cout << "v[i] : " << v[i] << std::endl;
	}
	z = (z/ m); //Calcul de la moyenne du prix des sous-jacents
	return payoff(z); //on recupere le payoff de cette moyenne
}

	//Renvoie si l'option est Asiatique
bool AsianOption::isAsianOption()
{
	throw true;
}