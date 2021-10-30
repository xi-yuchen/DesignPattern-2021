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
#include <string>
#include "shop.h"
#include "shopFilter.h"
#include "../Basic/welcome.h"
#include "../Customer/Customer.h"
#

class ShopFactory {
public:
    Shop* createShop(string type);
};

class shopInterface {

private:
    list<Shop*> _shopList;
    ShopFactory _shopFactory; // Factory Mode. In order to create some shops by users or admins.

public:

    void showAllShops();// Explore all the existing shop.

    Shop* createShop(string type); // Create a shop by admin.

    void addRemark(int ID, Customer* customer); // Add remarks to a certain shop.

    void editStorage(int ID); //Edit the shop's storage.

    void checkShop(int ID); //Check the specified shop.

    void initialize(); //Initial the start data to operate.

    void mainInterface(Customer* customer); // Main interface of the shop manage part.

    void filterShopByScore(); // Filter all the shops by their score.

    void manageGoods(int ID); // Manage situation of goods of shop found by ID.

    void showAllGoodsInShops(); // Show users all goods in each shop.

    void checkGoods(int ID); // Let users check goods list in one of the shops.
};

#endif //SOFTWAREARC_SHOPMANAGER_H