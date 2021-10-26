#ifndef _SHOP_SELLER_H_
#define _SHOP_SELLER_H_

#include<string>
#include<list>
#include"seller.h"
#include"commodity_seller.h"

using std::string;
using std::list;

class ShopSeller {
protected:
	int ID;
	string name, type, date; //店铺名称，店铺经营类型，店铺创建日期
	list<string*> commentList; //店铺评论列表
	list<CompositeCommoditySeller*> commodityList; //店铺商品列表
	Seller* owner; //店铺拥有者

public:
	ShopSeller(int ID, string name, string type, string date, list<string*> commentList, list<CompositeCommoditySeller*> commodityList, Seller* seller);

	string GetName() { return this->name; }
	string GetType() { return this->type; }
	string GetDate() { return this->date; }
	list<string*> GetCommentList() { return this->commentList; }
	list<CompositeCommoditySeller*> GetCommodityList() { return this->commodityList; }
	Seller* GetOwner() { return this->owner; }

	virtual bool HasComment(string* comment) = 0;
	virtual void AddComment(string* comment);
	virtual bool RemoveComment(string* comment);
	virtual void DisplayCommentList();

	virtual bool HasCommodity(CompositeCommoditySeller* commodity) = 0;
	virtual bool AddCommodity(CompositeCommoditySeller* commodity);
	virtual bool RemoveCommodity(CompositeCommoditySeller* commodity);
	virtual void DisplayCommodityList();
};

#endif