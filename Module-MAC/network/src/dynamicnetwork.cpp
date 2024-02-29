#include "dynamicnetwork.h"


DynamicNetwork::DynamicNetwork(TimeCounter* _timecounter, Graph* _graph, Collective* _collective) :
    timecounter_(_timecounter), graph_(_graph), collective_(_collective)
{
    distribute();
}
DynamicNetwork::~DynamicNetwork()
{
    clear();
    list_.clear();
}

void DynamicNetwork::setMASModel(MASModel* _model, FiniteDifferenceMethod* _scheme)
{
    models_[_model->getVariableName()] = std::pair(_model, _scheme);
}

Collective* DynamicNetwork::getCollective()
{
    return collective_;
}
TimeCounter* DynamicNetwork::getTimeCounter()
{
    return timecounter_;
}


//! Основная функция:
void DynamicNetwork::synchronize()
{
    fill();
    while(!timecounter_->isFinished()) {
        timecounter_->shift();
        std::cout << "Iteration number of: " << timecounter_->getCount() << std::endl;
        for (auto iModel: models_) {
            state_["r"] = collective_->getSystemVector(iModel.first);
            iModel.second.second->shift(state_);
        }
        /*
        for(auto iModel : models_)
        {
            if(iModel.second.first->getVariableName() != "state") {
                while(!iModel.second.first->getTimeCounter()->isFinished()) {
                    iModel.second.first->getTimeCounter()->shift();
                    iModel.second.second->shift(collective_->getSystemVector(iModel.first));
                }
                iModel.second.first->getTimeCounter()->reset();
            } else {
                iModel.second.second->shift(collective_->getSystemVector(iModel.first));
            }
        }
         */
        fill();
        /*if (timecounter_->getCount() >= 490000) {
            fill();
        }*/
    }
    std::cout << "DifferentialEquation is compute!"    << std::endl
              << "Exit..."              << std::endl;
    timecounter_->reset();
    std::cout << "Task is completed: success" << std::endl;
}

//! Функции для сохранения и сброса данных:
void DynamicNetwork::clear()
{
    desync_.clear();
    order_.clear();
    solve_.clear();
    weights_.clear();
}
void DynamicNetwork::dump(std::string _address, std::string _name)
{
    std::string fullAddress;
    for (auto &iParameter : list_)
    {
        fullAddress = _address + _name + "_" + iParameter +".txt";
        std::ofstream out1(fullAddress, std::ios::out | std::ios::binary);
        if (iParameter == "solve")
        {
            for (auto &iAgent : solve_)
            {
                for (auto &iAction : iAgent.second)
                {
                    /*
                    out1 << iAgent.first  << "   "
                         << iAction.first << "   " << iAction.second.first << "   " << iAction.second.second
                         << "\n";
                    */
                    out1 << iAgent.first  << "   "
                         << iAction.first << "   " << iAction.second.first(0) << "   " << iAction.second.first(1) << "   "
                         << iAction.second.second(0)
                         << "\n";
                }
                out1 << std::endl;
            }

        }
        if (iParameter == "weight") {
            for (auto &iTimeSet : weights_)
            {
                for (auto &iEdge : iTimeSet.second)
                {
                    out1 << iTimeSet.first    << "   "
                         << iEdge.first.first << "   " << iEdge.first.second << "   " << iEdge.second
                         << "\n";
                }
                out1 << std::endl;
            }

        }
        if (iParameter == "desync") {
            for (auto &iTimeSet : desync_)
            {
                out1 << iTimeSet.first << "   " <<iTimeSet.second
                     << std::endl;
            }

        }
        if (iParameter == "order") {
            for (auto &iTimeSet : order_)
            {
                out1 << iTimeSet.first << "   " <<iTimeSet.second
                     << std::endl;
            }

        }
        out1.close();
    }
}
void DynamicNetwork::setDumpParameter(std::string _parameter)
{
    list_.push_back(_parameter);
}
void DynamicNetwork::fill()
{
    if (!list_.empty())
    {
        //collective->update();
        //std::cout << collective->getMeanState() << std::endl;

        for (auto &iParameter : list_)
        {
            if (iParameter == "desync")
            {
               //desync_.push_back(std::make_pair(getTimeCounter()->getTimeValue(), collective->getDesyncValue()));
            }
            else
            {
                for (auto &iAgent : *collective_->getAgents())
                {
                    if (iParameter == "weight")
                    {
                        for (auto &iTriplet : iAgent->getTriplet())
                        {
                            weights_[getTimeCounter()->getTimeValue()].push_back(
                                    std::make_pair(std::make_pair(iAgent->getNumber(), iTriplet.first->getAgent()->getNumber()),
                                                   iTriplet.first->getEdge()->getRealWeight()));
                        }
                    }
                    if (iParameter == "solve")
                    {
                        //std::cout << iAgent->getAction("phase")->getValue() << std::endl;
                        /*
                        solve_[iAgent->getNumber()].push_back(std::make_pair(getTimeCounter()->getTimeValue(),
                                                                             std::make_pair(iAgent->getAction("state")->getValue(), iAgent->getControl())));
                        */
                        solve_[iAgent->getNumber()].push_back(std::make_pair(getTimeCounter()->getTimeValue(),
                                                                             std::make_pair(iAgent->getAction("state")->getValue(),
                                                                                            iAgent->getAction("phase")->getValue())));
                    }
                    if (iParameter == "order")
                    {
                        int n = 0;
                        double sum = 0.0;
                        for (auto &iAgent : *collective_->getAgents())
                        {
                            for (auto iNeighbor : *iAgent->getNeighbors())
                            {
                                sum += iNeighbor.second->getRealWeight();
                                n++;
                            }
                        }
                        order_.push_back(std::make_pair(getTimeCounter()->getTimeValue(),
                                                        sum / n));
                    }
                }
            }
        }
    }
}



//! (protected):
void DynamicNetwork::distribute()
{
    for(auto iAgent : *collective_->getAgents())
    {
        iAgent->setVertex(graph_->getVertex(iAgent->getNumber()));
    }
    collective_->create();
}
