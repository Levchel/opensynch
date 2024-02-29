#ifndef LINEARMODEL_H
#define LINEARMODEL_H

#include "masmodel.h"

struct LinearModel
        : public  MASModel
{
    LinearModel(TimeCounter* _timecounter, Protocol* _protocol, std::string _namevalue);
    VectorXd getEquationFunction(VectorXd& _svector) override;

    void setEquation(std::pair<MatrixXd, MatrixXd> _pair);

    //MatrixXd getBasicMatrix();
    //MatrixXd getControlMatrix();
private:
    VectorXd cupvector_;
    VectorXd vector;
    MatrixXd A_;
    MatrixXd B_;
};

#endif // LINEARMODEL_H
