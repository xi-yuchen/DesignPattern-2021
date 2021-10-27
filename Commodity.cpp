#include <iostream>
#include <iomanip>
#include "Commodity.h"
#include "shop.h"

using std::cout;
using std::endl;

//===================== Commodity 商品虚基类========================

Commodity::Commodity(int ID, string name, int price, Shop* shop) {
    this->ID = ID;
    this->name = name;
    this->price = price;
    this->shop = shop;
}

/**
 * 功能: 在商品组合中添加商品
 * 默认返回false
 */
bool Commodity::Add(Commodity* commodity) {
    return false;
}

/**
 * 功能: 在商品组合中移除商品
 * 默认返回false
 */
bool Commodity::Remove(Commodity* commodity) {
    return false;
}

//===================== SingleCommodity 单件商品类 ========================

SingleCommodity::SingleCommodity(int ID, string name, int price, Shop* shop, int amount)
    : Commodity(ID, name, price, shop) {
    commodity_list.push_back(this);
    this->amount = amount;
}

/**
 * 功能: 判断商品组合是否含有某种商品
 * 参数: 指向商品基类的指针
 * 对于SingleCommodity类, 仅判断函数参数指向的商品是否是自己
 */
bool SingleCommodity::HasCommodity(Commodity* commodity) {
    if(commodity = this) return true;
    else return false;
}

/**
 * 功能: 判断商品库存是否充足
 */
bool SingleCommodity::Enough(int amount) {
    if(amount > this->amount) return false;
    else return true;
}

/**
 * 功能: 商品售出
 * 参数: 购买数量
 * 如果库存充足则减少库存数量并返回true, 否则返回false
 */
bool SingleCommodity::Sell(int amount) {
    if(Enough(amount)) {
        this->amount -= amount;
        return true;
    }
    else return false;
}

/**
 * 功能: 显示商品信息
 */
void SingleCommodity::Display() {
    cout << "ID: ";
    cout << std::left << std::setw(4) << this->ID;
    cout << "商品名称: ";
    cout << std::left << std::setw(10) << this->name;
    cout << "库存数量: ";
    cout << std::left << std::setw(6) << this->amount;
    cout << "价格: ";
    cout << std::left << std::setw(6) << this->ID;
    cout << "商铺: ";
    cout << std::left << std::setw(8) << this->shop->getShopName();
    cout << endl;
}

//===================== CompositeCommodity 组合商品类 ========================

CompositeCommodity::CompositeCommodity(int ID, string name, int price, Shop* shop)
    : Commodity(ID, name, price, shop) { }

/**
 * 功能: 在商品组合中添加商品
 * 如果组合中已经有此商品则返回false, 否则添加商品并返回true
 */
bool CompositeCommodity::Add(Commodity* commodity) {
    if(HasCommodity(commodity)) { // 组合商品中已经存在此商品
        return false;
    }
    else { // 组合商品中不存在此商品 
        this->commodity_list.push_back(commodity);
        return true;
    }
}

/**
 * 功能: 在商品组合中移除商品
 * 如果组合中没有此商品则返回false, 否则移除商品并返回true
 */
bool CompositeCommodity::Remove(Commodity* commodity) {
    if(HasCommodity(commodity)) { // 组合商品中存在此商品
        this->commodity_list.remove(commodity);
        return true;
    }
    else return false; // 组合商品中不存在此商品 
}

/**
 * 功能: 判断商品组合是否含有某种商品
 * 参数: 指向商品基类的指针
 * 对于CompositeCommodity类, 依次判断组合中的每个商品是否含有此商品
 */
bool CompositeCommodity::HasCommodity(Commodity* commodity) {
    for(auto my_commodity : this->commodity_list) {
        if(my_commodity->HasCommodity(commodity)) { // 如果某件商品含有此商品
            return true;
        }
    }
    return false;
}

/**
 * 功能: 商品售出
 * 参数: 购买数量
 * 依次判断组合中的每个商品库存是否充足
 */
bool CompositeCommodity::Enough(int amount) {
    for(auto my_commodity : this->commodity_list) {
        if(!my_commodity->Enough(amount)) { // 如果某件商品的库存不充足
            return false;
        }
    }
    return true;
}

/**
 * 功能: 商品售出
 * 参数: 购买数量
 * 如果每个商品都有充足库存, 则依次售出组合中的每个商品
 */
bool CompositeCommodity::Sell(int amount) {
    if(Enough(amount)) { // 判断每件商品的库存都充足
        for(auto my_commodity : this->commodity_list) {
            my_commodity->Sell(amount);
        }
        return true;
    }
    else return false; // 有商品库存不足
}

/**
 * 功能: 显示组合商品信息, 并依次展示单价商品信息
 */
void CompositeCommodity::Display() {
    cout << "ID: ";
    cout << std::left << std::setw(4) << this->ID;
    cout << "商品组合: ";
    cout << std::left << std::setw(10) << this->name;
    cout << "商铺: ";
    cout << std::left << std::setw(8) << this->shop->getShopName();
    cout << endl;
    cout << "{" << endl;
    for(auto my_commodity : this->commodity_list) {
        my_commodity->Display();
    }
    cout << "}" << endl;
}

//===================== CommodityIterator 商品迭代器 ========================

CommodityIterator::CommodityIterator(list<Commodity*>::iterator commodity) {
    current = commodity;
}

CommodityIterator& CommodityIterator::operator= (const CommodityIterator& iter) {
    this->current = iter.current;
    return *this;
}

bool CommodityIterator::operator!= (const CommodityIterator& iter) {
    return this->current != iter.current;
}

bool CommodityIterator::operator== (const CommodityIterator& iter) {
    return this->current == iter.current;
}

CommodityIterator& CommodityIterator::operator++ () {
    current++;
    return *this;
}

CommodityIterator& CommodityIterator::operator++ (int) {
    CommodityIterator temp = *this;
    current++;
    return temp;
}