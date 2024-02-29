//
// Created by Kirill on 01.11.2023.
//

#include "verletscheme.h"


VerletScheme::VerletScheme(DifferentialEquation* _equation) :
        FiniteDifferenceMethod(_equation)
{

}

void VerletScheme::shift(std::map<std::string, VectorXd*> _state)
{
    //std::cout << "Iteration number of: " << timecounter_->getCount() << std::endl;
    if (timecounter_->getCount() == 0) {
        x0_ = (*_state["r"]);
        (*_state["r"]) += 2 * (*_state["v"])
                + 0.5 * pow(2, 2)
                * (getEquation()->getEquationFunction(*_state["r"]));


    }
    else {
        //std::cout << "x0: " << x0_ <<"\n" << std::endl;
        //std::cout << "x1: " << x1_ << std::endl;
        x1_ = (*_state["r"]);
        (*_state["r"]) = 2.0 * x1_ - x0_ + pow(timecounter_->getTimeStep(), 2)
                 * (getEquation()->getEquationFunction(*_state["r"]));
        x0_ = x1_;
        (*_state["v"]) = (*_state["v"])  + timecounter_->getTimeStep()
                 * (getEquation()->getEquationFunction(*_state["r"]));
    }
}
void VerletScheme::solve(std::map<std::string, VectorXd*>& _state)
{
    while(!timecounter_->isFinished())
    {
        timecounter_->shift();
        shift(_state);
    }
    std::cout << "DifferentialEquation is move!"    << std::endl
              << "Exit..."              << std::endl;
    timecounter_->reset();
}