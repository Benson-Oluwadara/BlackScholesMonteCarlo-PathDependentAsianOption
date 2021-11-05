#include "PathDepOption.h"
PathDepOption::PathDepOption() {
    this->T = 0.0;
    this->n_step = 0;
    this->price = 0.0;
    this->price_error = 0.0;
}

PathDepOption::PathDepOption(double t, int n_) {
    this->T = t;
    this->n_step = n_;
    this->price = 0.0;
    this->price_error = 0.0;
}
PathDepOption::~PathDepOption() {

}
void PathDepOption::PriceByMc(BSModel& bs, long N) {

}
double PathDepOption::Payoff(SamplePath& s) {
    return 0.0;
}