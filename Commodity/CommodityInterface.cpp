//
// Created by liruijie666 on 2021/10/30.
//
#include <utility>
#include <vector>
#include "CommodityInterface.h"

using namespace std;

void CommodityInterface::Initialize(shopInterface &shopInterface) {

    CommodityInformation *s1 = commodityFactory.getSingleCommodity(10, "熟食", 15, 1, 1000);
    map<CommodityInformation *, int> tempList = shopInterface.getCommodityList();
    tempList[s1]++;
    shopInterface.setCommodityList(tempList);
}

void CommodityInterface::MainInterface(shopInterface &shopInterface) {
    Initialize(shopInterface);
}
