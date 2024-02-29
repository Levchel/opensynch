#include "eulerscheme.h"

/*
double SymplexIntegration::getIntegral(std::function<double(ph::GreenKernel*, Vector3d, Vector3d)> _function, ph::GreenKernel* _green, Vector3d _r, BoundaryElement* _element)
{
    integral = 0.0;
    for (unsigned long i = 0; i < numNodes; i++)
    {
        integral += weightes[i] * _function(_green, _r, getTrianglePosition(i, _element));
    }
    return integral * _element->getArea();
}
*/

EulerScheme::EulerScheme(DifferentialEquation* _model) :
    FiniteDifferenceMethod(_model)
{

}

void EulerScheme::shift(std::map<std::string, VectorXd*> _state)
{
    //std::cout << "Iteration number of: " << timecounter_->getCount() << std::endl;
    //std::cout << "t = " << timecounter_->getTimeValue() << std::endl;
    //std::cout << getEquation()->getEquationFunction(*_x) << std::endl;
    (*_state["r"]) += timecounter_->getTimeStep() * (getEquation()->getEquationFunction((*_state["r"])));
}
void EulerScheme::solve(std::map<std::string, VectorXd*>& _state)
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
