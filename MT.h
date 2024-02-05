#pragma once
#include <random>
#include <memory>

class MT
{
public:
	//Methodes
	MT(const MT&) = delete;
	MT& operator=(const MT&) = delete;
	static MT& getInstance();
	std::mt19937 getMT19937();
	static double rand_unif();
	static double rand_norm();

private:
	//Constructeur
	MT();

	//Attribut
	std::mt19937 MT_gen;
};

