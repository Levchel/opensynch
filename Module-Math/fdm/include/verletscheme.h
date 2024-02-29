//
// Created by Kirill on 01.11.2023.
//

#ifndef MODULE_DYNAMICS_VERLETSCHEME_H
#define MODULE_DYNAMICS_VERLETSCHEME_H

#include "finitedifferencemethod.h"


struct VerletScheme :
        public FiniteDifferenceMethod
{
    VerletScheme()
    {

    }
    VerletScheme(DifferentialEquation*);
    void shift(std::map<std::string, VectorXd*> _X);
    void solve(std::map<std::string, VectorXd*>& _X);
private:
    VectorXd x0_, x1_;
};


#endif //MODULE_DYNAMICS_VERLETSCHEME_H
