#include <iostream>
#include "BSModel.h"
#include "PathDepOption.h"
#include"AsianCallOption.h"
#include"AsianPUTOption.h"
//#include<vector>
using namespace std;

int main()
{
    BSModel bs(100, 0.03, 0.2);
    double T = 1.0 / 12.0, K = 100.0; int m = 100;
    PathDepOption* pt = new AsianCallOption(K, T, m);
    pt->PriceByMc(bs, 10000);
    pt = new AsianPUTOption(K, T, m);
    cout << endl;
    pt->PriceByMc(bs, 10000);

    return 0;
}
