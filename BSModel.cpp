#include "BSModel.h"
#include<iostream>
#include"cmath"
#include <stdlib.h>
#include <time.h>
using namespace std;

const double pi = 4.0 * atan(1.0);
BSModel::BSModel() {
    this->Stock = 0.0;
    this->RiskFreeRate = 0.0;
    this->Sigma = 0.0;
}
BSModel::BSModel(double st, double r, double sig) {
    this->Stock = st;
    this->RiskFreeRate = r;
    this->Sigma = sig;
    srand(time(NULL));
}

double BSModel::getRiskFreeRate()const {
    return this->RiskFreeRate;
}

double BSModel::getSigma()const {
    return this->Sigma;
}

double BSModel::getStock()const {
    return this->Stock;
}

double BSModel::gauss() {
    double U1 = (rand() + 1.0) / (RAND_MAX + 1.0);
    double U2 = (rand() + 1.0) / (RAND_MAX + 1.0);

    //cout<<"U1="<<U1<<" "<<"U2="<<U2<<endl;
    return sqrt(-2.0 * log(U1)) * cos(2.0 * pi * U2);
}

void BSModel::generateSamplePath(int n, double T, SamplePath& s) {
    for (int i = 0; i < n; i++) {
        s[i] = this->getStock() * exp((this->getRiskFreeRate() - this->getSigma() * this->getSigma() * 0.5) * T / n + this->getSigma() * sqrt(T / n) * this->gauss());
        //cout<<"Sample path Generated:"<<s[i]<<endl;
    }
}
