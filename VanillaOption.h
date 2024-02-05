#pragma once
#include "Option.h"

//Class Option type
enum class OptionType { Call, Put };

class VanillaOption : public Option
{
private:
    //Attribut 
    double _strike;
public:
    //Constructeur
    VanillaOption(double e, double s);

    //Methodes
    virtual OptionType GetOptionType() = 0;
    double getStrike();
    friend class BlackScholesPricer;
   
};

