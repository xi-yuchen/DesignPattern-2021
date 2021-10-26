#include<iostream>
#include<iomanip>
#include"shop_seller.h"

using std::cout;
using std::endl;

ShopSeller::ShopSeller(int ID, string name, string type, string date, list<string*> commentList, list<CompositeCommoditySeller*> commodityList, Seller* seller) {
	this->ID = ID;
	this->name = name;
	this->type = type;
	this->date = date;
	this->commentList = commentList;
	this->commodityList = commodityList;
	this->owner = seller;
}

/*
功能：添加店铺评论
*/
void ShopSeller::AddComment(string* comment) {
	this->commentList.push_back(comment);
}

/*
功能：展示店铺评论
*/
void ShopSeller::DisplayCommentList() {
	cout << "店铺评论：" << endl;
	for (auto my_comment : this->commentList) {
		cout << *my_comment << endl;
	}
}

/*
功能：判断店铺商品列表中是否含有某种商品
参数：指向商品基类的指针
*/
bool ShopSeller::HasCommodity(CompositeCommoditySeller* commodity) {
	for (auto my_commodity : this->commodityList) {
		if (my_commodity->HasCommodity(commodity)) {
			return true;
		}
	}
}

/*
功能：在店铺商品列表中添加商品
参数：如果列表中已存在此商品则返回false，否则添加商品并返回true
*/
bool ShopSeller::AddCommodity(CompositeCommoditySeller* commodity) {
	if (HasCommodity(commodity)) { //此店铺已存在这种商品
		return false;
	}
	else {
		this->commodityList.push_back(commodity);
		return true;
	}
}

/*
功能：在店铺商品列表中移除商品
参数：如果列表中不存在此商品则返回false，否则删除商品并返回true
*/
bool ShopSeller::RemoveCommodity(CompositeCommoditySeller* commodity) {
	if (HasCommodity(commodity)) { //此店铺已存在这种商品
		this->commodityList.remove(commodity);
		return true;
	}
	else return false;
}

/*
功能：显示店铺商品列表
*/
void ShopSeller::DisplayCommodityList() {
	cout << "商品列表：" << endl;
	for (auto my_composite_commodity : this->commodityList) {
		cout << "ID: ";
		cout << std::left << std::setw(4) << this->ID;
		cout << "商品组合: ";
		cout << std::left << std::setw(10) << this->name;
		cout << endl;
		cout << "{" << endl;
/*		for (auto my_commodity : CompositeCommpditySeller::commodity_list) {
			
		}
		cout << "}" << endl; */
	}
}
