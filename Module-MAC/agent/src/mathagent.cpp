#include "mathagent.h"

MathAgent::MathAgent(int _number, State* _state) :
    Agent(_number)
{
    setPercept(_state);
}
/*
MathAgent::MathAgent(int _number, VectorXd _state, std::vector<Target*> targets_) :
    Agent(_number, _state, targets_)
{
    flagState_ = true;
}
*/

void MathAgent::setPercept(State* _state)
{
    states_[_state->getName()] = _state;
    dim_++;
}
void MathAgent::setControl(VectorXd _control)
{
    control_ = _control;
}

State* MathAgent::getAction(std::string _key)
{
    return states_[_key];
}

VectorXd MathAgent::getControl()
{
    return control_;
}
