#include "shop.h"

// 店铺评价类函数 - 获取评价详细信息
void ShopRemark::getRemark() {
    {
        cout << "--remark--" << endl;
        cout << "remark date: " << _remarkDate << endl;
        cout << "remark user: " << _remarkUser << endl;
        cout << "remark body: " << _remarkBody << endl;
    }
}

// 派生子类函数 - 获取店铺信息
void foodShop::execute() {
    {
        cout << "Shop Name: " + _shopName << endl;
        cout << "Shop ID: " << _shopID << endl;
        cout << "Shop Type: " + _shopType << endl;
        cout << "Shop Date: " + _shopDate << endl;
        for (auto remark : _shopRemarks) {
            remark->getRemark();
        }
    }
}

// 派生子类函数 - 获取店铺信息
void clothesShop::execute() {
    {
        cout << "Shop Name: " + _shopName << endl;
        cout << "Shop ID: " << _shopID << endl;
        cout << "Shop Type: " + _shopType << endl;
        cout << "Shop Date: " + _shopDate << endl;
        for (auto remark : _shopRemarks) {
            remark->getRemark();
        }
    }
}