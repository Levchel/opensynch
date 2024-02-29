#ifndef MASMODEL_H
#define MASMODEL_H

#include "model.h"
#include "protocol.h"
#include "collective.h"

struct MASModel
        : public DifferentialEquation
{
    MASModel(TimeCounter* timeCounter, Protocol* _protocol);

    void setCollective(Collective* _collective);

    Protocol* getProtocol()
    {
        return protocol_;
    }
protected:
    Protocol* protocol_;
    Collective* collective_;
};

#endif // MASMODEL_H
