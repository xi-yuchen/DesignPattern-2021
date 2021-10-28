#include<iostream>
#include"seller.h"

using std::cout;
using std::endl;

Seller::Seller(list<ShopSeller*> shopList) {
	this->shopList = shopList;
}

/*
功能：判断店铺列表中是否有某个店铺
参数：指向店铺的指针
*/
bool Seller::HasShop(ShopSeller* shop) {
	for (auto my_shop : this->shopList) {
		if (shop == my_shop) return true;
	}
	return false;
}

/*
功能：添加店铺
*/
bool Seller::AddShop(ShopSeller* shop) {
	if (HasShop(shop)) {
		return false;
	}
	else {
		this->shopList.push_back(shop);
		return true;
	}
}

/*
功能：移除店铺
*/
bool Seller::RemoveShop(ShopSeller* shop) {
	if (HasShop(shop)) {
		this->shopList.remove(shop);
		return true;
	}
	else return false;
}

/*
功能：展示店铺列表
*/
void Seller::DisplayShop() {
	cout << "店铺列表" << endl;
	for (auto my_shop : this->shopList) {
		cout << "店铺名称:" << my_shop->GetName;
		cout << "店铺类型:" << my_shop->GetType;
		cout << "店铺创建日期:" << my_shop->GetDate;
		cout << endl;
	}
}
