#pragma once
#include <iostream>
#include <vector>


class Option
{
private:
    //Attribut
    double _expiry;
public:
    //Constructeur
    Option(double);

    //Methodes
    virtual double payoff(double) = 0;
    double GetExpiry();
    double payoffPath(std::vector<double>);
    bool isAsianOption();
    bool isAmericanOption();
};

