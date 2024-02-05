#include "CRRPricer.h"
#include <iostream>


//Constructeur par default
CRRPricer::CRRPricer()
{
	_option = nullptr;
	_asset_price = 0;
	_interest_rate = 0;
	_depth = 0;
	_up = 0;
	_down = 0;
}

//Constructeur pour Option
CRRPricer::CRRPricer(Option* option, int depth, double asset_price, double up, double down, double interest_rate) throw()
{
	try
	{
		option->isAsianOption();
		if (down < interest_rate && interest_rate < up)
		{
			_option = option;
			_asset_price = asset_price;
			_interest_rate = interest_rate;
			_depth = depth;
			_up = up;
			_down = down;
		}
		else
		{
			_option = option;
			_asset_price = asset_price;
			_depth = depth;
			_up = 10;
			_down = 0;
			_interest_rate = 5;
			std::cout << "U,D and R have been changed to respect the arbitrage.";
		}
		_s_prices = BinaryTree<double>(depth);
		_c_prices = BinaryTree<double>(depth);
		for (int n = 0; n <= _s_prices.getDepth(); n++)
		{
			for (int i = 0; i <= n; i++)
			{
				_s_prices.setNode(n, i, _asset_price * pow((1 + _up), i) * pow((1 + _down), n - i));
			}
		}
		for (int n = 0; n <= _c_prices.getDepth(); n++)
		{
			for (int i = 0; i <= n; i++)
			{
				_c_prices.setNode(n, i, 0.0);
			}
		}
	}
	catch (bool e)
	{
		std::cerr << "Cannot compute CRR for an Asian Option" << std::endl;
	}
}

//Constructeur pour AmericanOption
CRRPricer::CRRPricer(AmericanOption* option, int depth, double asset_price, double up, double down, double interest_rate) throw()
{
	try
	{
		option->isAsianOption();

		if (down < interest_rate && interest_rate < up)
		{
			_option = option;
			_asset_price = asset_price;
			_interest_rate = interest_rate;
			_depth = depth;
			_up = up;
			_down = down;
		}
		else
		{
			_option = option;
			_asset_price = asset_price;
			_depth = depth;
			_up = 10;
			_down = 0;
			_interest_rate = 5;
			std::cout << "U,D and R have been changed to respect the arbitrage.";
		}
		_s_prices = BinaryTree<double>(depth);
		_c_prices = BinaryTree<double>(depth);

		for (int n = 0; n <= _s_prices.getDepth(); n++)
		{
			for (int i = 0; i <= n; i++)
			{
				_s_prices.setNode(n, i, _asset_price * pow((1 + _up), i) * pow((1 + _down), n - i));
			}
		}

		for (int n = 0; n <= _c_prices.getDepth(); n++)
		{
			for (int i = 0; i <= n; i++)
			{
				_c_prices.setNode(n, i, 0.0);
			}
		}
	}
	catch (bool e)
	{
		std::cerr << "Cannot compute CRR for an Asian Option" << std::endl;
	}
}

//Constructeur pour AsianOption
CRRPricer::CRRPricer(AsianOption* option, int depth, double asset_price, double up, double down, double interest_rate)
{
	try
	{
		option->isAsianOption();

		if (down < interest_rate && interest_rate < up)
		{
			_option = option;
			_asset_price = asset_price;
			_interest_rate = interest_rate;
			_depth = depth;
			_up = up;
			_down = down;
		}
		else
		{
			_option = option;
			_asset_price = asset_price;
			_depth = depth;
			_up = 10;
			_down = 0;
			_interest_rate = 5;
			std::cout << "U,D and R have been changed to respect the arbitrage.";
		}
		_s_prices = BinaryTree<double>(depth);
		_c_prices = BinaryTree<double>(depth);

		for (int n = 0; n <= _s_prices.getDepth(); n++)
		{
			for (int i = 0; i <= n; i++)
			{
				_s_prices.setNode(n, i, _asset_price * pow((1 + _up), i) * pow((1 + _down), n - i));
			}
		}

		for (int n = 0; n <= _c_prices.getDepth(); n++)
		{
			for (int i = 0; i <= n; i++)
			{
				_c_prices.setNode(n, i, 0.0);
			}
		}
	}
	catch (bool e)
	{
		std::cerr << "Cannot compute CRR for an Asian Option" << std::endl;
	}
}

//Constructeur pour Option avec la volatilite
CRRPricer::CRRPricer(Option* option, int depth, double asset_price, double r, double volatility) throw()
{
	try
	{
		option->isAsianOption();

		_option = option;
		_depth = depth;
		_asset_price = asset_price;
		double h = _option->GetExpiry() / depth; // h=T/N

		_up = exp(volatility * sqrt(h)) - 1;
		_down = exp(-volatility * sqrt(h)) - 1;
		_interest_rate = exp(r * h)-1;

		_s_prices = BinaryTree<double>(depth);
		_c_prices = BinaryTree<double>(depth);

		for (int n = 0; n <= _s_prices.getDepth(); n++)
		{
			for (int i = 0; i <= n; i++)
			{
				_s_prices.setNode(n, i, _asset_price * pow((1 + _up), i) * pow((1 + _down), n - i));
			}
		}

		for (int n = 0; n <= _c_prices.getDepth(); n++)
		{
			for (int i = 0; i <= n; i++)
			{
				_c_prices.setNode(n, i, 0.0);
			}
		}
		if (_option->isAmericanOption())
		{
			_exercise_condition.setDepth(_depth);
		}
	}
	catch (bool e)
	{
		std::cerr << "Cannot compute CRR for an Asian Option" << std::endl;
	}
}

//Methodes
	//Recuperation des prix simulés du stock
BinaryTree<double> CRRPricer::GetSimPrices() const
{
	return _s_prices;
}

	//Recuperation des prix simulés de l'option
BinaryTree<double> CRRPricer::GetSimCalls() const
{
	return _c_prices;
}

	//Recuperation de la condition d'exercice
BinaryTree<bool> CRRPricer::GetExerciseCondition() const
{
	return _exercise_condition;
}

	//Calcul des prix simules de notre option
void CRRPricer::compute()
{
	double S(0.0);
	double z(0.0);
	double H(0.0);
	double h = 0;
	double H_inter = 0;
	double R(_interest_rate);
	double U(_up);
	double D(_down);
	double q((R - D) / (U - D));
	bool b;
	_exercise_condition.setDepth(_depth);

	for (int n = _depth; n >= 0; n--)
	{
		for (int i = 0; i <= n; i++)
		{
			S = _s_prices.getNode(n, i); //prix simulé du stock avec l'arbre
			z = _option->payoff(S); 
			if (n == _depth) //Calcul du prix a maturite
			{
				H = z;
				_c_prices.setNode(n, i, H);
			}
			else
			{
				if (_option->isAmericanOption() == true) //Pour option amercaine
				{
					h = _option->payoff(S);
					H_inter = (q * _c_prices.getNode(n + 1, i + 1) + (1 - q) * _c_prices.getNode(n + 1, i) / (1 + R));
					H = std::max(h, H_inter);
					_exercise_condition.setBool(n, i, ((h >= H_inter) ? true : false));
				}
				else //Pour Vanille ou Digitale 
				{
					H = (q * _c_prices.getNode(n + 1, i + 1) + (1 - q) * _c_prices.getNode(n + 1, i)) / (1 + R);

				}
				_c_prices.setNode(n, i, H);
			}
		}
	}
}

	//Calcul du prix de l'option
double CRRPricer::operator()(bool closed_form)
{
	compute(); //Computation of the option prices in the tree
	if (closed_form == true)
	{
		double S(0.0);
		double z(0.0);
		double N(_depth);
		double R(_interest_rate);
		double U(_up);
		double D(_down);
		double q((R - D) / (U - D));
		double cumsum(0.0);
		double facto(1.0);

		for (int i = 0; i < N; i++)
		{
			S = _s_prices.getNode(N, i); //Recuperation du prix du stock simulé
			z = _option->payoff(S); // calcul du payoff
			cumsum += facto * pow(q, i) * pow((1 - q), N - i) * z;
			facto = facto * (double(N) - i) / (double(i) + 1);
		}

		double H0 = cumsum / pow((1 + R), N);
		return H0;
	}
	else
	{
		return _c_prices.getNode(0, 0);
	}
}

	//Recuperation de la valeur de S0
double CRRPricer::GetAssetPrice() const
{
	return _asset_price;
}

	//Recuperation de la valeur de r
double CRRPricer::GetInterestRate() const
{
	return _interest_rate;
}

	//Recuperation de la profondeur
int CRRPricer::GetDepth() const
{
	return _depth;
}

	//Recuperation de la valeur du Up
double CRRPricer::GetUp() const
{
	return _up;
}

	//Recuperation de la valeur du Down
double CRRPricer::GetDown() const
{
	return _down;
}

	//Recuperation de la valeur de H
double CRRPricer::GetH(int n, int i) const
{
	return _c_prices.getNode(n, i);
}

	//Calcule d'une factorielle
double CRRPricer::Factorial(double k)
{
	if (k == 0 || k == 1)
	{
		return 1;
	}
	else
	{
		return k * Factorial(k - 1);
	}
}

	//Recuperation de la condition d'exercice
bool CRRPricer::getExercise(int n, int i)
{
	return _exercise_condition.getNode(n, i);
}

