#ifndef _SELLER_H_
#define _SELLER_H_

#include<string>
#include<list>
#include"shop_seller.h"

using std::string;
using std::list;

class Seller {
protected:
	list<ShopSeller*> shopList;

public:
	Seller(list<ShopSeller*> shopList);

	virtual bool HasShop(ShopSeller* shop);
	virtual bool AddShop(ShopSeller* shop);
	virtual bool RemoveShop(ShopSeller* shop);
	virtual void DisplayShop();
};

#endif