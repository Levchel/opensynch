#ifndef AGENT_H
#define AGENT_H

#include <mathlist.h>
#include "vertex.h"
#include "edge.h"


struct Neighbor
{
    Neighbor(Agent* _agent, Edge* _edge) :
        agent_(_agent), edge_(_edge)
    {

    }
    Agent* getAgent()
    {
        return agent_;
    }
    Edge* getEdge()
    {
        return edge_;
    }
private:
    //int number_;
    Agent* agent_;
    Edge* edge_;
};


struct State
{
    explicit State(std::string _name)
    {
        name_ = std::move(_name);
    }
    int getDimension()
    {
        return value_.size();
    }
    std::string getName()
    {
        return name_;
    }
    VectorXd getValue()
    {
        return value_;
    }
    virtual void setValue(VectorXd _value) = 0;
protected:
    std::string name_;
    VectorXd value_;
};

struct Phase
        : public State
{
    explicit Phase(VectorXd _value) :
            State("phase")
    {
        value_ = _value;
    }
    void setValue(VectorXd _value) override
    {
        /*
        if (_state > 2.0 * ph::pi() or _state < 0.0)
        {
            sign(_state);
            state_ = _state - 2.0 * ph::pi();
        }
        */
        value_ = _value;
    }
};

struct Coordinate
        : public State
{
    explicit Coordinate(VectorXd _value);
    void setValue(VectorXd _value) override
    {
        value_ = _value;
    }
};


struct Agent        
{
    explicit Agent(int _number);

    void setVertex(Vertex* _vertex);
    void setNeighbors();
    void setTriplet();

    Vertex* getVertex();
    std::vector<std::pair<Agent*, Edge*>>* getNeighbors();
    //std::vector<std::pair<Agent*, Edge*>> getNeighborsCopy();
    std::vector<std::pair<Neighbor*, Neighbor*>> getTriplet();

    int getNumber();
    int getDimension();

    std::map<std::string, State*>* getStates()
    {
        return &states_;
    }

    virtual void setPercept(State* _state) = 0;
    virtual void setControl(VectorXd _control) = 0;
    virtual State* getAction(std::string _name) = 0;
    virtual VectorXd getControl() = 0;


protected:
    int dim_;
    int number_;
    int numNeighbors;
    int numTriplets;
    VectorXd control_;
    Vertex* vertex_;


    std::map<std::string, State*> states_;
    std::vector<std::pair<Agent*, Edge*>> neighbors_;
    std::vector<std::pair<Neighbor*, Neighbor*>> triplet_;
};


#endif // AGENT_H
