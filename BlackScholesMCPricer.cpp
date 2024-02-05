#include "BlackScholesMCPricer.h"
#include <math.h>  
#include "AsianOption.h"


//Constructeurs
BlackScholesMCPricer::BlackScholesMCPricer(Option* option, double initial_price, double interest_rate, double volatility)
{
	_option = option;
	_initial_price = initial_price;
	_interest_rate = interest_rate;
	if (_option->isAsianOption())
	{
		_volatility = 1 / sqrt(3) * volatility;
	}
	else
	{
		_volatility = volatility;
	}
}

//Destructeurs
BlackScholesMCPricer::~BlackScholesMCPricer(){}

//Methodes
	//Obtention du nombre de branches genereees
int BlackScholesMCPricer::getNbPaths() const
{
	return NbPaths;
}

	//Generation du prix de l'option par la methode de Monte Carlo
void BlackScholesMCPricer::generate(int nb_paths)
{
	std::vector<double> spot_paths; //Stock des prix generer par la formule de Wiener
	double spot_t;
	double z;
	double payoffs = 0;
	double new_price_estimate = 0;
	int m = 0; //Nombre de periode de la simulation
	std::vector<double> timesteps;
	estimates_mean = 0; // Moyenne des prix de l'option calculés
	estimates_variance = 0; // variance des prix de l'option calculés

	if (_option->isAsianOption())
	{
		m = ((AsianOption*)_option)->GetTimeSteps().size();
	}
	else //Option Vanille ou Digitale 
	{
		m = 1;
	}
	double T = _option->GetExpiry();
	double deltaT = T / m;
	for (int t = 0; t <= m; t++)
	{
		timesteps.push_back(t * deltaT);
	}
	for (int i = 0; i < nb_paths; i++) //Pour chaque sequence de prix simulé
	{
		spot_paths.push_back(_initial_price);
		for (int k = 0; k < m; k++) //k : periode actuelle
		{
			z = MT::rand_norm();
			spot_t = spot_paths[k] * exp((_interest_rate - (_volatility * _volatility) / 2) * (timesteps[k + 1] - timesteps[k]) + _volatility * sqrt(timesteps[k + 1] - timesteps[k]) * z); //Formule de Wiener
			spot_paths.push_back(spot_t);
		}
		payoffs = _option->payoffPath(spot_paths) + payoffs; //Calcul de la somme des Payoff
		spot_paths.clear();

	}
	//Calcul du prix d'option
	new_price_estimate = exp(-_interest_rate * T) * (1 /double(nb_paths))* payoffs ;
    estimates_mean = new_price_estimate * double(nb_paths) + estimates_mean;
	estimates_variance = pow(new_price_estimate * double(nb_paths), 2) + estimates_variance;
	_price_estimate = (_price_estimate * NbPaths + new_price_estimate * nb_paths) / double(NbPaths + nb_paths);
	estimated_prices.push_back(new_price_estimate);
	NbPaths = nb_paths + NbPaths;
}

	//Obtention du prix de l'action par l'operateur ()
double BlackScholesMCPricer::operator()()
{
	try
	{
		if (NbPaths == 0)
		{
			throw std::string("No Monte Carlo generation has been called previously.");
		}
		return _price_estimate;
	}
	catch (const std::string& e)
	{
		std::cerr << e << std::endl;
	}
}

	//Calcul de l'intervalle de confiance de notre prix d'option
std::vector<double> BlackScholesMCPricer::confidenceInterval()
{
	std::vector<double> CI;

	double upper_bound, lower_bound;

	lower_bound = estimates_mean - 1.96 * (sqrt(1 / double(NbPaths) * estimates_variance - pow(1 / double(NbPaths) * estimates_mean, 2) / NbPaths));
	upper_bound = estimates_mean + 1.96 * (sqrt(1 / double(NbPaths) * estimates_variance - pow(1 / double(NbPaths) * estimates_mean, 2) / NbPaths));
	CI = { lower_bound, upper_bound };
	return CI;
}