#include "AsianPUTOption.h"
#include<iostream>
#include"cmath"
using namespace std;
AsianPUTOption::AsianPUTOption() :PathDepOption() {

}

AsianPUTOption::AsianPUTOption(double k_, double T_, int n_) : PathDepOption(T_, n_) {
    this->K = k_;
}

AsianPUTOption::~AsianPUTOption() {

}

double AsianPUTOption::Payoff(SamplePath& s) {
    double average = 0.0;
    for (int k = 0; k < n_step; k++) {
        average += s[k];
    }
    average /= n_step;
    if (average < K) {
        return K - average;
    }
    else {
        return 0.0;
    }
}

void AsianPUTOption::PriceByMc(BSModel& bs, long N) {
    double H = 0.0;
    double H_sq = 0.0;
    for (int i = 0; i < N; i++) {
        SamplePath S(n_step);
        bs.generateSamplePath(n_step, T, S);
        //cout<<"Sample Path:"<<S[i]<<endl;
        H += Payoff(S);
        H_sq += pow(Payoff(S), 2);

    }
    H /= N;
    H_sq /= N;
    price = exp(-bs.getRiskFreeRate() * this->T) * H;
    price_error = exp(-bs.getRiskFreeRate() * this->T) * sqrt(H_sq - H * H) / sqrt(N - 1.0);

    cout << "Monte carlo Asian Put price:" << price;
    cout << endl;
    cout << "Pricing error:" << price_error;
}


