#include <iostream>
#include "Facade.h"
#include"Commodity.h"
#include<vector>
using namespace std;


int main(int argc, char* argv[])
{
    Facade* facade = new Facade();
    facade->BrowseAc();
    facade->BrowseAd();
    vector<Commodity*> Commoditylist;
    Commodity* temp = new SingleCommodity(41, "a", 900.0f, nullptr, 2);
    Commoditylist.push_back(temp);
    temp = new SingleCommodity(25, "b", 400.0f, nullptr, 1);
    Commoditylist.push_back(temp);
    facade->CalOptimalDecision(Commoditylist);
    facade->RecommendActivity(Commoditylist);
    delete facade;
    return 0;
}
