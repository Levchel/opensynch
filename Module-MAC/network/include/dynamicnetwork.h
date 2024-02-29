#ifndef DYNAMICNETWORK_H
#define DYNAMICNETWORK_H

// #pragma once

#include <mathlist.h>
#include "graph.h"
#include "agent.h"
#include "collective.h"
#include "masmodel.h"
#include "finitedifferencemethod.h"

struct DynamicNetwork
{
    DynamicNetwork(TimeCounter* _timecounter, Graph* _graph, Collective* _collective);
    ~DynamicNetwork();

    void setMASModel(MASModel* _model, FiniteDifferenceMethod* _scheme);

    Collective* getCollective();
    TimeCounter* getTimeCounter();

//! Основная функция:
    void synchronize();

//! Функции для сохранения и сброса данных:
    void clear();
    void fill();
    void dump(std::string _address, std::string _name);
    void setDumpParameter(std::string _parameter);

private:
    TimeCounter* timecounter_;
    Graph* graph_;
    Collective* collective_;
    std::map<std::string, std::pair<MASModel*,FiniteDifferenceMethod*>> models_;

    std::map<std::string, VectorXd*> state_;

    void distribute();

//! Переменные для сохранения данных:
    std::list<std::string> list_;
    std::vector<std::pair<double, double>> desync_;
    std::vector<std::pair<double, double>> order_;
    std::map<double, std::vector<std::pair<std::pair<int, int>, double>>> weights_;
    std::map<int, std::vector<std::pair<double, std::pair<VectorXd, VectorXd>>>> solve_;
};

#endif // DYNAMICNETWORK_H
