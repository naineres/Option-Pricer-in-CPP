#pragma once
#include "Option.h"
#include "BinaryTree.h"
#include "AsianOption.h"
#include "AmericanOption.h"
#include "VanillaOption.h"
#include "DigitalOption.h"
#include <ctime>
#include <functional>


class CRRPricer
{
public:
	//Constructeurs
	CRRPricer(Option* option, int depth, double asset_price, double up, double down, double interest_rate);
	CRRPricer(AsianOption* option, int depth, double asset_price, double up, double down, double interest_rate);
	CRRPricer(AmericanOption* option, int depth, double asset_price, double up, double down, double interest_rate);
	CRRPricer(Option* option, int depth, double asset_price, double r, double volatility);
	CRRPricer();
	
	//Methodes
	Option option() const;
	double GetAssetPrice() const;
	double GetInterestRate() const;
	int GetDepth() const;
	double GetUp() const;
	double GetDown() const;
	BinaryTree<double> GetSimPrices() const;
	BinaryTree<double> GetSimCalls() const;
	BinaryTree<bool> GetExerciseCondition() const;
	void compute();
	double operator()(bool = false);
	double GetH(int n, int i) const;
	double Factorial(double k);
	bool getExercise(int, int);

private:
	//Attributs
	Option* _option;
	double _asset_price;   //S0
	double _interest_rate; //r
	int _depth;			   //N
	double _up;
	double _down;
	BinaryTree<double> _s_prices; //Stockage des prix des stocks
	BinaryTree<double> _c_prices; //Stockage des prix simulé de l'option
	BinaryTree<bool> _exercise_condition; //Stockage d'un bool pour les prix simulé de l'option
};

// Pour verifier les valeurs : 
// https://www.math.drexel.edu/~pg/fin/VanillaCalculator.html