#ifndef EULERSCHEME_H
#define EULERSCHEME_H

#include "finitedifferencemethod.h"


struct EulerScheme :
        public FiniteDifferenceMethod
{
    EulerScheme()
    {

    }
    EulerScheme(DifferentialEquation*);
    void shift(std::map<std::string, VectorXd*> _X);
    void solve(std::map<std::string, VectorXd*>& _X);
};


#endif // EULERSCHEME_H
