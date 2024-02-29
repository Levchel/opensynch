#ifndef COLLECTIVE_H
#define COLLECTIVE_H

#include "agent.h"
#include "timecounter.h"

struct Collective
{
    Collective();
    ~Collective();

    void clear();
    void create(); // Создает систему после добавления всех агентов.
    void update(std::string _name);      // Обновляет вектор состояний системы на основании расчетных векторов.

    void setAgent(Agent* _agent);
    void setSystemVector(VectorXd& _svector, const std::string& _key);

    int getAgentCount();
    long long getSystemVectorDim(const std::string& _key);
    VectorXd* getSystemVector(const std::string& _key);
    std::map<std::string, VectorXd>* getSystemVectors();
    std::vector<Agent*>* getAgents();

//! (2) Функции для обработки данных:
    //double getMeanState();
    //double getDesyncValue();
    //VectorXd getMinState();
    //VectorXd getMaxState();

private:
    int numAgents_;
    TimeCounter* timecounter;
    std::vector<Agent*> agents_;
    std::map<std::string, VectorXd> svectors_;
//! (2) Вспомогательные переменные:
    VectorXd cupvector_;

    void setSystemVectors(Agent* _agent);
};

#endif // COLLECTIVE_H
