#ifndef _ORDER_SELLER_H_
#define _ORDER_SELLER_H_

#include<list>
#include"commodity_seller.h"

using std::string;
using std::list;

class OrderItemSeller { //订单中的单个商品条目，可以是单一商品也可以是复合商品
protected:
	int amount;

	SingleCommoditySeller* singleCommodity = nullptr;
	CompositeCommoditySeller* compositeCommodity = nullptr;

	double totalPrice = 0;

public:
	OrderItemSeller(SingleCommoditySeller* singleCommodity, CompositeCommoditySeller* compositeCommodity, int amount);
	
	SingleCommoditySeller* GetSingleCommodityPtr();
	CompositeCommoditySeller* GetCompositeCommodityPtr();
	int GetAmount() const { return amount; }

	void SetTotalPrice(SingleCommoditySeller* singleCommodity, CompositeCommoditySeller* compositeCommodity, int amount);
	double GetTotalPrice() const { return totalPrice; }
};

class OrderSeller {
protected:
	int orderID;
	int price = 0; //订单总价
	list<CommoditySeller> items; //订单内容

public:
	string state = "unfinished";

	OrderSeller(int orderID);

	void Add(OrderItemSeller* item);
	void Remove(OrderItemSeller* item);
	double GetTotalPrice();

	void PayAll();
	void Pay(OrderItemSeller* item);
	
	int GetOrderID() const { return orderID; }

	void Display();
};

#endif