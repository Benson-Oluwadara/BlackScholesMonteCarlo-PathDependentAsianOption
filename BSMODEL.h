#ifndef BSMODEL_H
#define BSMODEL_H
#include<vector>
using namespace std;

typedef vector<double> SamplePath;
class BSModel {
private:
    double Stock;//stock price
    double RiskFreeRate;//RiskFreeRate
    double Sigma;//Volatility
    //double time;//time to maturity
public:
    BSModel();
    BSModel(double st, double r, double sig);
    double getStock() const;//get stock price
    double getRiskFreeRate() const; //get riskfreerate
    double getSigma() const; //get volatility
   // double getTime() const ; //get time
    double gauss();
    void generateSamplePath(int n, double T, SamplePath& s);

};
#endif // BSMODEL_H

