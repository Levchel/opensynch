#ifndef MODEL_H
#define MODEL_H

#include "mathlist.h"
#include "timecounter.h"

struct DifferentialEquation
{
    std::string getVariableName();
    TimeCounter* getTimeCounter();
    virtual VectorXd getEquationFunction(VectorXd&) = 0;
protected:
    std::string namevalue_;
    TimeCounter* timecounter_;
};

#endif // MODEL_H
