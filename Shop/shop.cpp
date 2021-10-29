#include "shop.h"

void Shop::showShopInformation() {
    cout << "Shop ID: " << _shopID << endl;
    cout << "Shop Name: " + _shopName << endl;
    cout << "Shop Type: " + _shopType << endl;
    cout << "Shop Date: " + _shopDate << endl;
    cout << "Shop Storage: " << _shopStorage << endl;
    cout << "Shop Remark Score:" << this->getTotalRemarkScore() << endl;
    cout << "--Remark Starts Here--" << endl;
    for (ShopRemark *shopRemark:_shopRemarks) {
        cout << shopRemark->getRemarkDate() << endl;
        cout << shopRemark->getRemarkUser() << endl;
        cout << shopRemark->getRemarkBody() << endl;

    }
    cout << "--Remark Ends Here--" << endl;
    cout << endl;
}

void foodShop::accept(Visitor &v) {
    return v.visit(this);
}

foodShop::foodShop(const string &shopName, int shopId, const string &shopType, const string &shopDate, int shopStorage,
                   double shopScore, const list<ShopRemark *> &shopRemarks, const map<string, int> &itemList) : Shop(
        shopName, shopId, shopType, shopDate, shopStorage, shopScore, shopRemarks, itemList) {}


void drinkShop::accept(Visitor &v) {
    return v.visit(this);
}

drinkShop::drinkShop(const string &shopName, int shopId, const string &shopType, const string &shopDate,
                     int shopStorage, double shopScore, const list<ShopRemark *> &shopRemarks,
                     const map<string, int> &itemList) : Shop(shopName, shopId, shopType, shopDate, shopStorage,
                                                              shopScore, shopRemarks, itemList) {}


void digitalShop::accept(Visitor &v) {
    return v.visit(this);
}

digitalShop::digitalShop(const string &shopName, int shopId, const string &shopType, const string &shopDate,
                         int shopStorage, double shopScore, const list<ShopRemark *> &shopRemarks,
                         const map<string, int> &itemList) : Shop(shopName, shopId, shopType, shopDate, shopStorage,
                                                                  shopScore, shopRemarks, itemList) {}


void bookShop::accept(Visitor &v) {
    return v.visit(this);
}

bookShop::bookShop(const string &shopName, int shopId, const string &shopType, const string &shopDate, int shopStorage,
                   double shopScore, const list<ShopRemark *> &shopRemarks, const map<string, int> &itemList) : Shop(
        shopName, shopId, shopType, shopDate, shopStorage, shopScore, shopRemarks, itemList) {}


void dailyShop::accept(Visitor &v) {
    return v.visit(this);
}

dailyShop::dailyShop(const string &shopName, int shopId, const string &shopType, const string &shopDate,
                     int shopStorage, double shopScore, const list<ShopRemark *> &shopRemarks,
                     const map<string, int> &itemList) : Shop(shopName, shopId, shopType, shopDate, shopStorage,
                                                              shopScore, shopRemarks, itemList) {}


void furnitureShop::accept(Visitor &v) {
    return v.visit(this);
}

furnitureShop::furnitureShop(const string &shopName, int shopId, const string &shopType, const string &shopDate,
                             int shopStorage, double shopScore, const list<ShopRemark *> &shopRemarks,
                             const map<string, int> &itemList) : Shop(shopName, shopId, shopType, shopDate, shopStorage,
                                                                      shopScore, shopRemarks, itemList) {}


void clothesShop::accept(Visitor &v) {
    v.visit(this);
}

clothesShop::clothesShop(const string &shopName, int shopId, const string &shopType, const string &shopDate,
                         int shopStorage, double shopScore, const list<ShopRemark *> &shopRemarks,
                         const map<string, int> &itemList) : Shop(shopName, shopId, shopType, shopDate, shopStorage,
                                                                  shopScore, shopRemarks, itemList) {}


void stationeryShop::accept(Visitor &v) {
    return v.visit(this);
}

stationeryShop::stationeryShop(const string &shopName, int shopId, const string &shopType, const string &shopDate,
                               int shopStorage, double shopScore, const list<ShopRemark *> &shopRemarks,
                               const map<string, int> &itemList) : Shop(shopName, shopId, shopType, shopDate,
                                                                        shopStorage, shopScore, shopRemarks,
                                                                        itemList) {}


void sportShop::accept(Visitor &v) {
    return v.visit(this);
}

sportShop::sportShop(const string &shopName, int shopId, const string &shopType, const string &shopDate,
                     int shopStorage, double shopScore, const list<ShopRemark *> &shopRemarks,
                     const map<string, int> &itemList) : Shop(shopName, shopId, shopType, shopDate, shopStorage,
                                                              shopScore, shopRemarks, itemList) {}


void nullShop::accept(Visitor &v) {
    return v.visit(this);
}

nullShop::nullShop(const string &shopName, int shopId, const string &shopType, const string &shopDate, int shopStorage,
                   double shopScore, const list<ShopRemark *> &shopRemarks, const map<string, int> &itemList) : Shop(
        shopName, shopId, shopType, shopDate, shopStorage, shopScore, shopRemarks, itemList) {}
