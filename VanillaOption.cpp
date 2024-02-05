#include "VanillaOption.h"

// Constructeur
VanillaOption::VanillaOption(double e, double s) : Option(e) {
    _strike = s;
};

//Methode
    //Recuperation du Strike
double VanillaOption::getStrike() { return _strike; }