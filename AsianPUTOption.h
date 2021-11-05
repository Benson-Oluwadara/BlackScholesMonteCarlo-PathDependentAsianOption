#ifndef ASIANPUTOPTION_H
#define ASIANPUTOPTION_H
#include "PathDepOption.h"


class AsianPUTOption :public PathDepOption {
private:
    double K;//strike price
public:
    AsianPUTOption();
    ~AsianPUTOption();
    AsianPUTOption(double k_, double T_, int n_);
    double Payoff(SamplePath& s);
    void PriceByMc(BSModel& bs, long N);
};

#endif

