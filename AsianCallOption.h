#ifndef ASIANCALLOPTION_H
#define ASIANCALLOPTION_H
#include "PathDepOption.h"


class AsianCallOption :public PathDepOption {
private:
    double K;//strike price
public:
    AsianCallOption();
    ~AsianCallOption();
    AsianCallOption(double k_, double T_, int n_);
    double Payoff(SamplePath& s);
    void PriceByMc(BSModel& bs, long N);
};

#endif


