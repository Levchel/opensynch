#include "finitedifferencemethod.h"


FiniteDifferenceMethod::FiniteDifferenceMethod(DifferentialEquation* _model) :
        equation_(_model)
{
    timecounter_ = getEquation()->getTimeCounter();
    //setDumpAddress(_address, _name);
}

DifferentialEquation* FiniteDifferenceMethod::getEquation()
{
    return equation_;
}

