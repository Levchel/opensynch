#ifndef PROTOCOL_H
#define PROTOCOL_H

#include "agent.h"

struct Protocol
{
    Protocol()
    {

    }
    void setVariableName(std::string _name)
    {
        name_ = _name;
    }
    std::string getVariableName()
    {
        return name_;
    }
    virtual VectorXd getControlFunction(Agent* _agent) = 0;
protected:
    std::string name_;
};


#endif // PROTOCOL_H
