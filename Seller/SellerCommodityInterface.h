#ifndef DESIGNPATTERN_2021_SELLERCOMMODITYINTERFACE_H
#define DESIGNPATTERN_2021_SELLERCOMMODITYINTERFACE_H

#include "Commodity/Commodity.h"
#include "Commodity/CommodityFactory.h"
#include "Shop/shopInterface.h"
#include "SellerCommodityCommand.h"

using namespace std;

class SellerCommodityInterface {
public:
	void displayCommodity();
	void addCommodity();
	void removeCommodity();
	void hasCommodity();
};


#endif //DESIGNPATTERN_2021_COMMODITYINTERFACE_H