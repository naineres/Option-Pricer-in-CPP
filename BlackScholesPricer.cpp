#include "BlackScholesPricer.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include<iostream>
#include <string>




// Constructeur
BlackScholesPricer::BlackScholesPricer(VanillaOption* option1, double S1, double r1, double v1) {
    option = 'V';
    type = option1->GetOptionType();
    K = option1->_strike;
    T = option1->GetExpiry();
    S = S1;
    r = r1;
    v = v1;
}

// Constructeur
BlackScholesPricer::BlackScholesPricer(DigitalOption* option1, double S1, double r1, double v1) {
    option = 'D';
    type = option1->GetOptionType();
    K = option1->_digitalstrike;
    T = option1->GetExpiry();
    S = S1;
    r = r1;
    v = v1;
}

// Calcul de D1 de la Formule de Black Scholes
double  BlackScholesPricer::d1() {
    return (log(S / K) + (r + 0.5 * v * v) * T) / (v * (pow(T, 0.5)));
}

// Calcul de D2 de la Formule de Black Scholes
double  BlackScholesPricer::d2() {
    return (d1() - v * pow(T, 0.5));
}

// Calcul de la fonction de repartition de la loi normale
double  BlackScholesPricer::N(double d) {
    return std::erfc(-d / std::sqrt(2)) / 2;
}

// Calcul de prix de l'option : Call/Put
double  BlackScholesPricer::operator() () {
    int i = 1;
    if (option=='D')
    {
        if (type == OptionType::Put)
        {
            i = -1;
        }
        return(exp(-r * T) * N(i * d2()));
       }
    else {
        if (type == OptionType::Call)
        {
            i = 0;
        }
        return(pow(-1, i) * S * N(pow(-1, i) * d1()) - pow(-1, i) * K * exp(-r * T) * N(pow(-1, i) * d2()));

    }
}
    

// Calcul du delta de l'option
double BlackScholesPricer::delta() {
    int i = 1;
    if (option=='D')
    {
        if (type == OptionType::Put)
        {
            i = -1;
        }
        return((exp(-d2() * d2()) / pow(2 * 3.141592653589793238463, 0.5)) * i * exp(-r * T) / (pow(S, 2) * pow(v, 2) * T));
    }
    else
    {
        if (type == OptionType::Call)
        {
            i = 0;
        }
        return(N(d1()) - i);
    }
}
