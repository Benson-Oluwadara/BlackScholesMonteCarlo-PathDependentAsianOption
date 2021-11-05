#include<iostream>
#include"cmath"
#include"AsianCallOption.h"
using namespace std;
AsianCallOption::AsianCallOption() :PathDepOption() {

}

AsianCallOption::AsianCallOption(double k_, double T_, int n_) : PathDepOption(T_, n_) {
    this->K = k_;
}

AsianCallOption::~AsianCallOption() {

}

double AsianCallOption::Payoff(SamplePath& s) {
    double average = 0.0;
    for (int k = 0; k < n_step; k++) {
        average += s[k];
    }
    average /= n_step;
    if (average > K) {
        return average - K;
    }
    else {
        return 0.0;
    }
}

void AsianCallOption::PriceByMc(BSModel& bs, long N) {
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


    cout << "Monte carlo Asian call price:" << price;
    cout << endl;
    cout << "Pricing error:" << price_error;
}
