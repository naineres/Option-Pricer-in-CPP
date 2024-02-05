#include "MT.h"
#include <iostream>

//Constructeur
MT::MT()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	MT_gen = gen;
}

//Methode
	//Recuperation de l'adresse du singleton
MT& MT::getInstance()
{
	static std::unique_ptr<MT> instance(new MT());
	return *instance;
}

	//Recuperation du generateur de nombre aleatoire
std::mt19937 MT::getMT19937()
{
	return MT_gen;
}

	//Generation de nombres aléatoire suivant un distribution normale
double MT::rand_unif()
{
	std::uniform_real_distribution<double> uniform_pdf(0.0, 1.0);
	return uniform_pdf(getInstance().MT_gen);
}

	//Generation de nombres aléatoire suivant une distribution normale
double MT::rand_norm()
{
	std::normal_distribution<> gaussian_pdf(0.0, 1.0);
	return gaussian_pdf(getInstance().MT_gen);
}