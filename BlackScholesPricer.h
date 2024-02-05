#pragma once
#include "VanillaOption.h"
#include "DigitalOption.h"

class BlackScholesPricer
{
public:
    //Attribut
    char option;
    enum OptionType type; // Call ou Put
    double K;             // prix du Strike
    double T;             // Maturit�
    double S;             // Prix de l'option
    double r;             // Taux d'inter�t
    double v;             // Volatilit� du sous-jacent


    //Constructeurs
    BlackScholesPricer(VanillaOption* option, double S, double r, double v);  
    BlackScholesPricer(DigitalOption* option, double S, double r, double v);

    //Methode
    double d1();
    double d2();
    double N(double d); // Fonction de repartition de la loi normale 
    double operator() ();
    double delta();
    //Black Scholes formula
    //https://www.techno-science.net/definition/6256.html


};

