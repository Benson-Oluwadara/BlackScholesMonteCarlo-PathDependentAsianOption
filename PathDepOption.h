#ifndef PATHDEPOPTION_H
#define PATHDEPOPTION_H
#include"BSModel.h"

class PathDepOption {
public:
    double T;//time to maturity
    int n_step; //number of steps
    double price;
    double price_error;
public:
    PathDepOption();
    PathDepOption(double t, int n_);
    virtual ~PathDepOption();
    virtual double Payoff(SamplePath& s);
    virtual void PriceByMc(BSModel& bs, long N);
};

#endif // PATHDEPOPTION_H

