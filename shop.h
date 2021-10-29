#pragma once
#include<iostream>
#include <list>

using namespace std;
#ifndef SOFTWAREARC_SHOP_H
#define SOFTWAREARC_SHOP_H

//This .h file contains operations and attributions for a single shop.
class Visitor;//Used Visitor Design Pattern
class ShopRemark;

class ShopRemark {
public:
    string _remarkDate;
    string _remarkUser;
    string _remarkBody;

    ShopRemark(const string& remarkDate, const string& remarkUser, const string& remarkBody) :
        _remarkDate(remarkDate), _remarkUser(remarkUser), _remarkBody(remarkBody) {};

    void getRemark() {
        cout << "--remark--" << endl;
        cout << "remark date: " << _remarkDate << endl;
        cout << "remark user: " << _remarkUser << endl;
        cout << "remark body: " << _remarkBody << endl;
    }
};

class Shop { //template method
public:
    string _shopName;
    int _shopID;
    string _shopType;
    string _shopDate;
    int _shopStorage;
    list<ShopRemark*> _shopRemarks;

    virtual void execute() = 0;

    virtual void accept(Visitor& v) = 0;

    Shop(const string& shopName, int shopId, const string& shopType, const string& shopDate, int shopStorage,
        const list<ShopRemark*>& shopRemarks) : _shopName(shopName), _shopID(shopId), _shopType(shopType),
        _shopDate(shopDate), _shopStorage(shopStorage),
        _shopRemarks(shopRemarks) {}

    const string& getShopName() const {
        return _shopName;
    }

    int getShopId() const {
        return _shopID;
    }

    const string& getShopType() const {
        return _shopType;
    }

    const string& getShopDate() const {
        return _shopDate;
    }

    int getShopStorage() const {
        return _shopStorage;
    }

    const list<ShopRemark*>& getShopRemarks() const {
        return _shopRemarks;
    }

    void setShopName(const string& shopName) {
        _shopName = shopName;
    }

    void setShopId(int shopId) {
        _shopID = shopId;
    }

    void setShopType(const string& shopType) {
        _shopType = shopType;
    }

    void setShopDate(const string& shopDate) {
        _shopDate = shopDate;
    }

    void setShopStorage(int shopStorage) {
        _shopStorage = shopStorage;
    }

    void setShopRemarks(const list<ShopRemark*>& shopRemarks) {
        _shopRemarks = shopRemarks;
    }
};

class Visitor {
public:
    virtual void visit(Shop* shop) = 0;
};

class infoVisitor : public Visitor {
    void visit(Shop* shop) {
        shop->execute();
    }
};

class foodShop : public Shop {
public:
    void execute();

    void accept(Visitor& v);
    
    foodShop::foodShop(const string& shopName, int shopId, const string& shopType, const string& shopDate, int shopStorage,
    const list<ShopRemark*>& shopRemarks) : Shop(shopName, shopId, shopType, shopDate, shopStorage,
        shopRemarks) {}
};

void foodShop::execute() {
    cout << "Shop Name: " + _shopName << endl;
    cout << "Shop ID: " << _shopID << endl;
    cout << "Shop Type: " + _shopType << endl;
    cout << "Shop Date: " + _shopDate << endl;
    for (auto remark : _shopRemarks) {
        remark->getRemark();
    }
}

void foodShop::accept(Visitor& v) {
    v.visit(this);
}

class clothesShop : public Shop {
public:
    void execute();

    void accept(Visitor& v);

    clothesShop(const string& shopName, int shopId, const string& shopType, const string& shopDate, int shopStorage,
        const list<ShopRemark*>& shopRemarks) : Shop(shopName, shopId, shopType, shopDate, shopStorage,
            shopRemarks) {}
};

void clothesShop::execute() {
    cout << "Shop Name: " + _shopName << endl;
    cout << "Shop ID: " << _shopID << endl;
    cout << "Shop Type: " + _shopType << endl;
    cout << "Shop Date: " + _shopDate << endl;
    for (auto remark : _shopRemarks) {
        remark->getRemark();
    }
}

void clothesShop::accept(Visitor& v) {
    v.visit(this);
}

class nullShop : public Shop {
public:
    void execute();

    void accept(Visitor& v);

    nullShop(const string& shopName, int shopId, const string& shopType, const string& shopDate, int shopStorage,
        const list<ShopRemark*>& shopRemarks) : Shop(shopName, shopId, shopType, shopDate, shopStorage,
            shopRemarks) {}
};

void nullShop::execute() {
    cout << "Shop Name: " + _shopName << endl;
    cout << "Shop ID: " << _shopID << endl;
    cout << "Shop Type: " + _shopType << endl;
    cout << "Shop Date: " + _shopDate << endl;
    for (auto remark : _shopRemarks) {
        remark->getRemark();
    }
}

void nullShop::accept(Visitor& v) {
    v.visit(this);
}


class drinkShop : public Shop {
public:
    void execute();

    void accept(Visitor& v);

    drinkShop(const string& shopName, int shopId, const string& shopType, const string& shopDate, int shopStorage,
        const list<ShopRemark*>& shopRemarks) : Shop(shopName, shopId, shopType, shopDate, shopStorage,
            shopRemarks) {}
};

void drinkShop::execute() {
    cout << "Shop Name: " + _shopName << endl;
    cout << "Shop ID: " << _shopID << endl;
    cout << "Shop Type: " + _shopType << endl;
    cout << "Shop Date: " + _shopDate << endl;
    for (auto remark : _shopRemarks) {
        remark->getRemark();
    }
}

void drinkShop::accept(Visitor& v) {
    v.visit(this);
}


class digitalShop : public Shop {
public:
    void execute();

    void accept(Visitor& v);

    digitalShop(const string& shopName, int shopId, const string& shopType, const string& shopDate, int shopStorage,
        const list<ShopRemark*>& shopRemarks) : Shop(shopName, shopId, shopType, shopDate, shopStorage,
            shopRemarks) {}
};

void digitalShop::execute() {
    cout << "Shop Name: " + _shopName << endl;
    cout << "Shop ID: " << _shopID << endl;
    cout << "Shop Type: " + _shopType << endl;
    cout << "Shop Date: " + _shopDate << endl;
    for (auto remark : _shopRemarks) {
        remark->getRemark();
    }
}

void digitalShop::accept(Visitor& v) {
    v.visit(this);
}


class bookShop : public Shop {
public:
    void execute();

    void accept(Visitor& v);

    bookShop(const string& shopName, int shopId, const string& shopType, const string& shopDate, int shopStorage,
        const list<ShopRemark*>& shopRemarks) : Shop(shopName, shopId, shopType, shopDate, shopStorage,
            shopRemarks) {}
};

void bookShop::execute() {
    cout << "Shop Name: " + _shopName << endl;
    cout << "Shop ID: " << _shopID << endl;
    cout << "Shop Type: " + _shopType << endl;
    cout << "Shop Date: " + _shopDate << endl;
    for (auto remark : _shopRemarks) {
        remark->getRemark();
    }
}

void bookShop::accept(Visitor& v) {
    v.visit(this);
}

class dailyShop : public Shop {
public:
    void execute();

    void accept(Visitor& v);

    nullShop(const string& shopName, int shopId, const string& shopType, const string& shopDate, int shopStorage,
        const list<ShopRemark*>& shopRemarks) : Shop(shopName, shopId, shopType, shopDate, shopStorage,
            shopRemarks) {}
};

void dailyShop::execute() {
    cout << "Shop Name: " + _shopName << endl;
    cout << "Shop ID: " << _shopID << endl;
    cout << "Shop Type: " + _shopType << endl;
    cout << "Shop Date: " + _shopDate << endl;
    for (auto remark : _shopRemarks) {
        remark->getRemark();
    }
}

void dailyShop::accept(Visitor& v) {
    v.visit(this);
}

class furnitureShop : public Shop {
public:
    void execute();

    void accept(Visitor& v);

    nullShop(const string& shopName, int shopId, const string& shopType, const string& shopDate, int shopStorage,
        const list<ShopRemark*>& shopRemarks) : Shop(shopName, shopId, shopType, shopDate, shopStorage,
            shopRemarks) {}
};

void furnitureShop::execute() {
    cout << "Shop Name: " + _shopName << endl;
    cout << "Shop ID: " << _shopID << endl;
    cout << "Shop Type: " + _shopType << endl;
    cout << "Shop Date: " + _shopDate << endl;
    for (auto remark : _shopRemarks) {
        remark->getRemark();
    }
}

void furnitureShop::accept(Visitor& v) {
    v.visit(this);
}

class stationeryShop : public Shop {
public:
    void execute();

    void accept(Visitor& v);

    nullShop(const string& shopName, int shopId, const string& shopType, const string& shopDate, int shopStorage,
        const list<ShopRemark*>& shopRemarks) : Shop(shopName, shopId, shopType, shopDate, shopStorage,
            shopRemarks) {}
};

void stationeryShop::execute() {
    cout << "Shop Name: " + _shopName << endl;
    cout << "Shop ID: " << _shopID << endl;
    cout << "Shop Type: " + _shopType << endl;
    cout << "Shop Date: " + _shopDate << endl;
    for (auto remark : _shopRemarks) {
        remark->getRemark();
    }
}

void stationeryShop::accept(Visitor& v) {
    v.visit(this);
}

class sportShop : public Shop {
public:
    void execute();

    void accept(Visitor& v);

    sportShop(const string& shopName, int shopId, const string& shopType, const string& shopDate, int shopStorage,
        const list<ShopRemark*>& shopRemarks) : Shop(shopName, shopId, shopType, shopDate, shopStorage,
            shopRemarks) {}
};

void sportShop::execute() {
    cout << "Shop Name: " + _shopName << endl;
    cout << "Shop ID: " << _shopID << endl;
    cout << "Shop Type: " + _shopType << endl;
    cout << "Shop Date: " + _shopDate << endl;
    for (auto remark : _shopRemarks) {
        remark->getRemark();
    }
}

void sportShop::accept(Visitor& v) {
    v.visit(this);
}
#endif //SOFTWAREARC_SHOP_H
