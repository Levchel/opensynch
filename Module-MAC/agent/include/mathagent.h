#ifndef MATHAGENT_H
#define MATHAGENT_H

#include "agent.h"

struct MathAgent
        : public Agent
{
    MathAgent(int _number, State* _state);
    //MathAgent(int _number, VectorXd _state, std::vector<Target*> targets_);

    void setPercept(State* _state) override;
    void setControl(VectorXd _control)  override;

    State* getAction(std::string _key)  override;
    VectorXd getControl()  override;


    //void setVertex(Vertex* _vertex);
    //Vertex* getVertex();

    //int getNumber();
};

#endif // MATHAGENT_H
