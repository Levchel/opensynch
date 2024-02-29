#include "model.h"


std::string DifferentialEquation::getVariableName()
{
    return namevalue_;
};
TimeCounter* DifferentialEquation::getTimeCounter()
{
    return timecounter_;
}
/*
MatrixXd DifferentialEquation::getBasicMatrix()
{
    return basicmatrix_;
}
MatrixXd DifferentialEquation::getControlMatrix()
{
    return controlmatrix_;
}
*/

