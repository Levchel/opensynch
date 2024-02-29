#ifndef FINITEDIFFERENCEMETHOD_H
#define FINITEDIFFERENCEMETHOD_H

#include "model.h"

class FiniteDifferenceMethod
{
protected:
    DifferentialEquation* equation_;
    TimeCounter* timecounter_;
    DifferentialEquation* getEquation();
public:
    //bool flag_;
    //bool flagData_;
    std::string address_;
    std::string name_;
    explicit FiniteDifferenceMethod()
    {
        timecounter_ = getEquation()->getTimeCounter();
    }
    explicit FiniteDifferenceMethod(DifferentialEquation*);
    void setDifferentialEquation(DifferentialEquation* _equation)
    {
        equation_ = _equation;
        timecounter_ = getEquation()->getTimeCounter();
    }
    virtual void shift(std::map<std::string, VectorXd*> _X) = 0;
    virtual void solve(std::map<std::string, VectorXd*>& _X) = 0;

};


#endif // FINITEDIFFERENCEMETHOD_H
