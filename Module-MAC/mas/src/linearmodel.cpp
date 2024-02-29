#include "linearmodel.h"

LinearModel::LinearModel(TimeCounter* _timecounter,  Protocol* _protocol, std::string _namevalue) :
    MASModel(_timecounter, _protocol)
{
    //flagBasic_ = true;
    //flagControl_ = true;
    namevalue_ = _namevalue;
}

VectorXd LinearModel::getEquationFunction(VectorXd& _vector)
{
    //! (1) Set new (_)Vector:
    collective_->setSystemVector(_vector, namevalue_);
    //! (2) Set control vector:
    getProtocol()->setVariableName(namevalue_);
    //vector = VectorXd(collective->getSystemVectorDim());
    vector = VectorXd(_vector.size());

    int i = 0;
    for (auto &iAgent : *collective_->getAgents())
    {
        iAgent->setControl(protocol_->getControlFunction(iAgent));
        cupvector_ = iAgent->getControl();
        for (int s = 0; s < cupvector_.size(); s++)
        {
            vector(i) = cupvector_(s);
            i++;
        }
    }
    return vector;
}

void LinearModel::setEquation(std::pair<MatrixXd, MatrixXd> _pair)
{
    /*
    A_ = MatrixXd::Zero(collective->getStateDimension(),
                                  collective->getStateDimension());
    B_ = MatrixXd::Zero(collective->getStateDimension(),
                                    collective->getStateDimension());
    int s = 0;
    for (auto &iAgent : *collective->getAgents())
    {
        basicmatrix_.block(s,s,iAgent->getDimension(),iAgent->getDimension()) = _pair.first;
        controlmatrix_.block(s,s,iAgent->getDimension(),iAgent->getDimension()) = _pair.second;
        s = s + iAgent->getDimension();
    }
     */
}

