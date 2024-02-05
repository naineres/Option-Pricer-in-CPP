#pragma once
#include "Option.h"
#include "MT.h"


class BlackScholesMCPricer
{
public:
	//Constructeur
	BlackScholesMCPricer(Option* option, double initial_price, double interest_rate, double volatility);

	//Destructeur
	~BlackScholesMCPricer();

	//Methodes
	double operator()();
	void generate(int nb_paths);
	std::vector<double> confidenceInterval();
	int getNbPaths() const;

private:
	//Attributs
	Option* _option;
	double _initial_price;  //S0
	double _interest_rate;  //r
	double _volatility;     //sigma
	double _price_estimate; //Option price
	double estimates_mean;
	double estimates_variance;
	int NbPaths; //Nombre de branches generees depuis le debut 
	std::vector<double> estimated_prices; //stockage des prix estimes des options
};
