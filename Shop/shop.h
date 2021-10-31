#pragma once

#ifndef SOFTWAREARC_SHOP_H
#define SOFTWAREARC_SHOP_H

#include <iostream>
#include <list>
#include <string>
#include <map>
#include "../Commodity/Commodity.h"

using namespace std;

//This .h file contains operations and attributions for a single shop.
class Visitor;//Used Visitor Design Pattern
class ShopRemark;

class ShopRemark {
private:
    string _remarkDate;
    string _remarkUser;
    string _remarkBody;
    double _remarkScore;
public:


    ShopRemark(const string &remarkDate, const string &remarkUser, const string &remarkBody, double remarkScore)
            : _remarkDate(remarkDate), _remarkUser(remarkUser), _remarkBody(remarkBody), _remarkScore(remarkScore) {}

    const string &getRemarkDate() const {
        return _remarkDate;
    }

    const string &getRemarkUser() const {
        return _remarkUser;
    }

    const string &getRemarkBody() const {
        return _remarkBody;
    }

    double getRemarkScore() const {
        return _remarkScore;
    }

};

/*
 * Shop class:
 *      base class including fundamental attributions and virtual functions for abstract class.
 * functions:
 *      getters and setters for attributions: To get and set attributions.
 *      Construction function: To spawn a new class.
 * Tips: There are two virtual functions. They will be clarified in the concrete subclasses.
 */
class Shop {
private:
    string _shopName;
    int _shopID;
    string _shopType;
    string _shopDate;
    int _shopStorage;
    double _shopScore;
    list<ShopRemark *> _shopRemarks;
    map<CommodityInformation*, int> _itemList;

public:
    void showShopInformation();

    virtual void accept(Visitor &v) = 0;

    Shop(const string &shopName, int shopId, const string &shopType, const string &shopDate, int shopStorage,
         double shopScore, const list<ShopRemark *> &shopRemarks, const map<CommodityInformation*, int> &itemList) : _shopName(
            shopName), _shopID(shopId), _shopType(shopType), _shopDate(shopDate), _shopStorage(shopStorage), _shopScore(
            shopScore), _shopRemarks(shopRemarks), _itemList(itemList) {}

    const string &getShopName() const {
        return _shopName;
    }

    int getShopId() const {
        return _shopID;
    }

    const string &getShopType() const {
        return _shopType;
    }

    const string &getShopDate() const {
        return _shopDate;
    }

    int getShopStorage() const {
        return _shopStorage;
    }

    const list<ShopRemark *> &getShopRemarks() const {
        return _shopRemarks;
    }

    void setShopName(const string &shopName) {
        _shopName = shopName;
    }

    void setShopId(int shopId) {
        _shopID = shopId;
    }

    void setShopType(const string &shopType) {
        _shopType = shopType;
    }

    void setShopDate(const string &shopDate) {
        _shopDate = shopDate;
    }

    void setShopStorage(int shopStorage) {
        _shopStorage = shopStorage;
    }

    void
    addShopRemarks(const string &remarkDate, const string &remarkUser, const string &remarkBody, double remarkScore) {
        _shopRemarks.push_back(new ShopRemark(remarkDate, remarkUser, remarkBody, remarkScore));
    }

    const map<CommodityInformation*, int> &getItemList() const {
        return _itemList;
    }

    void setItemList(const map<CommodityInformation*, int> &itemList) {
        _itemList = itemList;
    }

    double getTotalRemarkScore() const {
        double totalScore = 0.00;
        for (auto _remark:_shopRemarks) {
            totalScore = totalScore + _remark->getRemarkScore();
        }
        int len = _shopRemarks.size();
        if (_shopRemarks.empty())
            return 0.00;
        else
            return totalScore / len;
    }

    void setRemarkScore(double shopScore) {
        _shopScore = shopScore;
    }
};

/*
 * Visitor Mode is below.
 * Through these visitors, different visitors can visit certain data by their need methods.
 * infoVisitor: Show detailed information of a shop.
 * filterVisitor: Show an outline information of a shop.
 */
class Visitor {
public:
    virtual void visit(Shop *shop) = 0;
};

class infoVisitor : public Visitor {
public:
    void visit(Shop *shop) {
        shop->showShopInformation();
    }
};

class filterVisitor : public Visitor {
public:
    void visit(Shop *shop) {
        cout << shop->getShopId() << " - 店铺名称: " << shop->getShopName() << endl;
    }
};

/*
 * Design pattern 'Template Method' is used below:
 *      Each subclasses will be defined and instancialized when user provides their information.
 * All the subclasses of the shop base class are below.
 * They are devided by actual types.
 * Each subclass contains three functions:
 *      showShopInformation(): Output detailed information of a shop.
 *      accept(): It should be used with Visitor mode. It will actually execute the visit() in Visitor mode.
 *      Constructor function of each subclass: spawn a new subclass with initial data.
 * Types: food, drink, digital, book, daily, furniture, clothes, stationery, sports, null.
 */
class foodShop : public Shop {
public:
    void accept(Visitor &v);

    foodShop(const string &shopName, int shopId, const string &shopType, const string &shopDate, int shopStorage,
             double shopScore, const list<ShopRemark *> &shopRemarks, const map<CommodityInformation*, int> &itemList);
};

class clothesShop : public Shop {
public:
    void accept(Visitor &v);

    clothesShop(const string &shopName, int shopId, const string &shopType, const string &shopDate, int shopStorage,
                double shopScore, const list<ShopRemark *> &shopRemarks, const map<CommodityInformation*, int> &itemList);
};

class drinkShop : public Shop {
public:
    void accept(Visitor &v);

    drinkShop(const string &shopName, int shopId, const string &shopType, const string &shopDate, int shopStorage,
              double shopScore, const list<ShopRemark *> &shopRemarks, const map<CommodityInformation*, int> &itemList);
};

class digitalShop : public Shop {
public:

    void accept(Visitor &v);

    digitalShop(const string &shopName, int shopId, const string &shopType, const string &shopDate, int shopStorage,
                double shopScore, const list<ShopRemark *> &shopRemarks, const map<CommodityInformation*, int> &itemList);
};

class bookShop : public Shop {
public:

    void accept(Visitor &v);

    bookShop(const string &shopName, int shopId, const string &shopType, const string &shopDate, int shopStorage,
             double shopScore, const list<ShopRemark *> &shopRemarks, const map<CommodityInformation*, int> &itemList);
};

class dailyShop : public Shop {
public:

    void accept(Visitor &v);

    dailyShop(const string &shopName, int shopId, const string &shopType, const string &shopDate, int shopStorage,
              double shopScore, const list<ShopRemark *> &shopRemarks, const map<CommodityInformation*, int> &itemList);
};

class furnitureShop : public Shop {
public:

    void accept(Visitor &v);

    furnitureShop(const string &shopName, int shopId, const string &shopType, const string &shopDate, int shopStorage,
                  double shopScore, const list<ShopRemark *> &shopRemarks, const map<CommodityInformation*, int> &itemList);
};

class stationeryShop : public Shop {
public:

    void accept(Visitor &v);

    stationeryShop(const string &shopName, int shopId, const string &shopType, const string &shopDate, int shopStorage,
                   double shopScore, const list<ShopRemark *> &shopRemarks, const map<CommodityInformation*, int> &itemList);
};

class sportShop : public Shop {
public:

    void accept(Visitor &v);

    sportShop(const string &shopName, int shopId, const string &shopType, const string &shopDate, int shopStorage,
              double shopScore, const list<ShopRemark *> &shopRemarks, const map<CommodityInformation*, int> &itemList);
};

/*
 * DesignPattern - 'Null Object Pattern'
 * In actual situations, users may don't know the information of their intended shops.
 * So they may pass some null or empty attributions or arguments.
 * For the robustness and multi-functional, the factory can provide a 'null shop':
 *      if there are some attributions or arguments null or empty, the relative values will be default values
 *      instead of informing users with an error message.
 */
class nullShop : public Shop {
public:

    void accept(Visitor &v);

    nullShop(const string &shopName, int shopId, const string &shopType, const string &shopDate, int shopStorage,
             double shopScore, const list<ShopRemark *> &shopRemarks, const map<CommodityInformation*, int> &itemList);
};

#endif //SOFTWAREARC_SHOP_H