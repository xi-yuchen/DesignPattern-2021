#include<iostream>
#include<iomanip>
#include"commodity_seller.h"

using std::cout;
using std::endl;

//===================== CommoditySeller 商品虚基类========================

CommoditySeller::CommoditySeller(int ID, string name, int price, ShopSeller* shop) {
	this->ID = ID;
	this->name = name;
	this->price = price;
	this->owner = shop;
}

/*
功能：在商品组合中添加商品
默认返回false
*/
bool CommoditySeller::Add(CommoditySeller* commodity) {
	return false;
}

/*
功能：在商品组合中移除商品
默认返回false
*/
bool CommoditySeller::Remove(CommoditySeller* commodity) {
	return false;
}

//===================== SingleCommoditySeller 单件商品类========================

SingleCommoditySeller::SingleCommoditySeller(int ID, string name, int price, ShopSeller* shop, int amount) 
	: CommoditySeller(ID, name, price, shop) {
	this->amount = amount;
}


/*
功能：判断商品组合中是否有某种商品
参数：指向商品基类的指针
对于SingleCommoditySeller类，仅判断函数参数指向的商品是否为自己
*/
bool SingleCommoditySeller::HasCommodity(CommoditySeller* commodity) {
	if (commodity = this) return true;
	else return false;
}

/*
功能：判断商品库存是否充足
*/
bool SingleCommoditySeller::Enough(int amount) {
	if (amount < this->amount) return true;
	else return false;
}

/*
功能：售出商品
参数：售出数量
如果库存充足则扣除库存数量并返回true，反之返回false
*/
bool SingleCommoditySeller::Sell(int amount) {
	if (Enough(amount)) {
		this->amount -= amount;
		return true;
	}
	else return false;
}

/*
功能：显示商品信息
*/
void SingleCommoditySeller::Display() {
	cout << "ID: ";
	cout << std::left << std::setw(4) << this->ID;
	cout << "商品名称: ";
	cout << std::left << std::setw(10) << this->name;
	cout << "库存数量: ";
	cout << std::left << std::setw(6) << this->amount;
	cout << "价格: ";
	cout << std::left << std::setw(6) << this->ID;
	cout << endl;
}

//===================== CompositeCommoditySeller 组合商品类 ========================

CompositeCommoditySeller::CompositeCommoditySeller(int ID, string name, int price, ShopSeller* shop) 
	:CommoditySeller(ID, name, price, shop) {	}

/*
功能：在商品组合中添加商品
如果商品组合中已有此商品则返回false，否则添加商品并返回true
*/
bool CompositeCommoditySeller::Add(CommoditySeller* commodity) {
	if (HasCommodity(commodity)) { //组合商品中已经存在此商品
		return false;
	}
	else { //组合商品中不存在此商品 
		this->commodity_list.push_back(commodity);
		return true;
	}
}

/*
功能：在商品组合中移除物品
如果商品组合中无此商品则返回false，否则移除商品并返回true
*/
bool CompositeCommoditySeller::Remove(CommoditySeller* commodity) {
	if (HasCommodity(commodity)) { //组合商品中存在此商品
		this->commodity_list.remove(commodity);
		return true;
	}
	else return false; //组合商品中不存在此商品 
}

/*
功能：判断商品组合是否含有某种商品
参数：指向商品基类的指针
对于CompositeCommoditySeller类，依次判断组合中的每个商品是否含有此商品
*/
bool CompositeCommoditySeller::HasCommodity(CommoditySeller* commodity) {
	for (auto my_commodity : this->commodity_list) {
		if (my_commodity->HasCommodity(commodity)) { //如果某件商品含有此商品
			return true;
		}
	}
	return false;
}

/*
功能：售出商品
参数：售出数量
依次判断组合商品中的单个商品库存是否充足
*/
bool CompositeCommoditySeller::Enough(int amount) {
	for (auto my_commodity : this->commodity_list) {
		if (!my_commodity->Enough(amount)) { //如果某件商品的库存不充足
			return false;
		}
	}
	return true;
}

/*
功能：售出商品
参数：购买商品
如果组合商品中的每一个单个商品库存数量都充足，则依次售出组合中的每个商品
*/
bool CompositeCommoditySeller::Sell(int amount) {
	if (Enough(amount)) { //判断每件商品的库存都充足
		for (auto my_commodity : this->commodity_list) {
			my_commodity->Sell(amount);
		}
		return true;
	}
	else return false; //有商品库存不足
}

/*
功能：显示组合商品信息，并依次展示单个商品价格信息
*/
void CompositeCommoditySeller::Display() {
	cout << "ID: ";
	cout << std::left << std::setw(4) << this->ID;
	cout << "商品组合: ";
	cout << std::left << std::setw(10) << this->name;
	cout << endl;
	cout << "{" << endl;
	for (auto my_commodity : this->commodity_list) {
		my_commodity->Display();
	}
	cout << "}" << endl;
}