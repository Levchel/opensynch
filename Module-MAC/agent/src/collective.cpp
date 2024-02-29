#include "collective.h"


Collective::Collective()
{
    numAgents_ = 0;
}
Collective::~Collective()
{
    clear();
}

void Collective::clear()
{
    numAgents_ = 0;
    agents_.clear();
}
void Collective::create()
{
    for (auto &iAgent : agents_)
    {
        iAgent->setNeighbors();
        iAgent->setTriplet();
    }
}
void Collective::update(std::string _key)
{
    int s = 0;
    for (auto &iAgent : agents_)
    {
        cupvector_ = iAgent->getAction(_key)->getValue();
        for (int i = 0; i < iAgent->getAction(_key)->getDimension(); i++)
        {
            cupvector_(i) = svectors_[_key](s + i);
        }
        iAgent->getAction(_key)->setValue(cupvector_);
        s = s + iAgent->getAction(_key)->getDimension();
    }
}

long long Collective::getSystemVectorDim(const std::string& _key)
{
    return svectors_[_key].size();
}
int Collective::getAgentCount()
{
    return numAgents_;
}
void Collective::setAgent(Agent* _agent)
{
    agents_.push_back(_agent);
    setSystemVectors(_agent);
    numAgents_++;
}
std::vector<Agent*>* Collective::getAgents()
{
    return &agents_;
}


VectorXd* Collective::getSystemVector(const std::string& _key)
{
    return &svectors_[_key];
}
std::map<std::string, VectorXd>* Collective::getSystemVectors()
{
    return &svectors_;
}
void Collective::setSystemVector(VectorXd& _svector, const std::string& _key)
{
    svectors_[_key] = _svector;
    update(_key);
}

/*
void Collective::setStateVector(Agent* _agent)
{
    cupvector_ = svector_;
    svector_.resize(getStateDimension() + _agent->getAction().size());
    svector_ << cupvector_, _agent->getAction();
    dim_ = getStateDimension() + _agent->getAction().size();
}

void Collective::setPhaseVector(Agent* _agent)
{
    if (_agent->isPhase())
    {
        cupvector_ = pvector_;
        pvector_.resize(pvector_.size() + 1);
        pvector_ << cupvector_, _agent->getPhase()->getState();
    }
}
*/

//! (2) Функции для обработки данных:
/*
double Collective::getMeanState()
{
    double sum = 0.0;
    for (auto iAgent1 : agents_)
    {
        for (auto iAgent2 : agents_)
        {
            sum += iAgent1->getAction()->getValue().norm();
        }
    }
    return sum / getAgentCount();
}
double Collective::getDesyncValue()
{
    double sum = 0.0;
    for (auto iAgent1 : agents_)
    {
        for (auto iAgent2 : agents_)
        {
            sum += pow((iAgent1->getAction() - iAgent2->getAction()).norm(), 2);
        }
    }
    return sum / getAgentCount() / (getAgentCount() - 1);
}
 */
/*
VectorXd Collective::getMinState()
{
    VectorXd vector;
    int s = 0;
    for (auto iAgent : agents_)
    {
        if (s == 0) {
            vector = iAgent->getAction();
        }
        else {
            if (iAgent->getAction().norm() < vector.norm()) {
                vector = iAgent->getAction();
            }
        }
        s++;
    }
    return vector;
}
VectorXd Collective::getMaxState()
{
    VectorXd vector;
    int s = 0;
    for (auto iAgent : agents_)
    {
        if (s == 0) {
            vector = iAgent->getAction();
        }
        else {
            if (iAgent->getAction().norm() > vector.norm()) {
                vector = iAgent->getAction();
            }
        }
        s++;
    }
    return vector;
}
*/

//! private:

void Collective::setSystemVectors(Agent* _agent)
{
    for (const auto& iState : *_agent->getStates())
    {
        if (svectors_.count(iState.first))
        {
            cupvector_ = svectors_[iState.first];
            svectors_[iState.first].conservativeResize(cupvector_.size() + _agent->getAction(iState.first)->getDimension());
            svectors_[iState.first] << cupvector_, iState.second->getValue();
        }
        else
        {
            svectors_[iState.first] = iState.second->getValue();
        }
    }
    std::cout << 1 << std::endl;
    /*
    svector_.conservativeResize(getStateDimension() + _agent->getAction().size());
    svector_ << cupvector_, _agent->getAction();
    dim_ = getStateDimension() + _agent->getAction().size();
     */
}

