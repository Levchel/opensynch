#include "masmodel.h"

MASModel::MASModel(TimeCounter* _timecounter, Protocol* _protocol) :
   protocol_(_protocol)
{
    timecounter_ = _timecounter;
}

void MASModel::setCollective(Collective* _collective)
{
    collective_ = _collective;
}




