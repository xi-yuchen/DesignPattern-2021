#pragma once
//
// Created by liruijie666 on 2021/10/25.
//
using namespace std;

#ifndef SOFTWAREARC_SHOPMANAGER_H
#define SOFTWAREARC_SHOPMANAGER_H

#include <iostream>
#include <list>
#include <utility>
#include "shop.h"

/*
*   Factory Mode-工厂模式，可以生产不同类型的店铺。
*   只需要输入一个类型的参数，即可以生产出对应的店铺（类型为指针）。
*   返回一个派生类的指针。
*/
class ShopFactory {
public:
    // 创建店铺的工厂。
    Shop* createShop(string type);
};

/*
*   查看店铺的相关操作，全部封装成了接口可供其他子系统调用。
*/
class shopInterface {
private:
    list<Shop*> _shopList;
    ShopFactory _shopFactory;

public:

    void showAllShops();

    Shop* createShop(string type);

    void editStorage(int ID);

    void initialize();

    void mainInterface();
};

#endif //SOFTWAREARC_SHOPMANAGER_H
