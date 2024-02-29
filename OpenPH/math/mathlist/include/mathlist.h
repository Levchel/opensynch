#ifndef MATH_H
#define MATH_H

#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include "Eigen/Eigen"
//include <fftw3.h>
#include <map>

using namespace Eigen;


typedef Vector3d Vector3d;
//typedef MatrixXd Matrix3d;
typedef MatrixXcd MatrixC;
typedef std::complex<double> cDoubles;

namespace ph {
    double kronecker(int i, int j);
    double pi();
    cDoubles i();
    double getRandomNumber(double fMin, double fMax);

    VectorXd getDirection(double _theta);

    double getExteriorProduct(Vector3d v1, Vector3d v2);
    Vector3d cross2D(Vector3d v);
    MatrixXd getKronProduct(VectorXd v1, VectorXd v2);
    Matrix3d getRotationMatrix3D(double _phi, double _theta);
    Matrix3d getRotationMatrix3D(std::string axis, double _phi);
    MatrixXd getPauliMatrix(int _number);
    //std::vector<std::complex<double>> applyFFT(std::vector<std::complex<double>> data);
}
/*
double approx(double, double, double);
Vector getOrtogonalVector(double x, double y);
Vector getUnitVector(Vector& vec);
Vector cross2D(Vector& vec_0);
Vector cross3D(Vector& a, Vector& b);
MatrixXd getRotationMatrix(double _phi);
MatrixXd getRotationMatrix(double _phi, double _theta);
VectorXd getInvertibleVector(VectorXd&);
MatrixXd getInvertibleMatrix(MatrixXd& A);
MatrixXd getKronProduct(VectorXd& v1, VectorXd& v2);
*/
#endif // MATH_H
