//
// Created by liruijie666 on 2021/10/30.
//

#ifndef DESIGNPATTERN_2021_COMMODITYINTERFACE_H
#define DESIGNPATTERN_2021_COMMODITYINTERFACE_H

#include "Commodity.h"
#include "CommodityFactory.h"
#include "../Shop/shopInterface.h"

using namespace std;

class CommodityInterface {
private:
    CommodityFactory commodityFactory;
public:
    void Initialize(shopInterface &shopInterface);

    void MainInterface(shopInterface &shopInterface);
};


#endif //DESIGNPATTERN_2021_COMMODITYINTERFACE_H
