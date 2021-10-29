#include "shopInterface.h"
#include <string>

infoVisitor infoVisitor;
filterVisitor filterVisitor;

/*  DesignPattern - 'Null Object Pattern'
 *  If the argument 'type' is null:
 *      The shop factory will create a nullshop with some default 'null' or 'empty' values
 *      instead of a message 'error type'.
 *  Else, the shop factory will create the relative type.
 */
Shop *ShopFactory::createShop(string type) {
    if (type == "")
        return new nullShop("unknown", 0, "unknown", "2021-01-01", 0, 0, list<ShopRemark *>(), map<string, int>());

    else if (type == "food")
        return new foodShop("newFoodshop", 1, "food", "2021-01-01", 0, 0, list<ShopRemark *>(), map<string, int>());

    else if (type == "drink")
        return new drinkShop("newDrinkshop", 2, "drink", "2021-01-01", 0, 0, list<ShopRemark *>(), map<string, int>());

    else if (type == "digital")
        return new digitalShop("newDigitalshop", 3, "digital", "2021-01-01", 0, 0, list<ShopRemark *>(),
                               map<string, int>());

    else if (type == "book")
        return new bookShop("newBookshop", 4, "book", "2021-01-01", 0, 0, list<ShopRemark *>(), map<string, int>());

    else if (type == "daily")
        return new dailyShop("newDailyshop", 5, "daily", "2021-01-01", 0, 0, list<ShopRemark *>(), map<string, int>());

    else if (type == "furniture")
        return new furnitureShop("newfurnitureshop", 6, "furniture", "2021-01-01", 0, 0, list<ShopRemark *>(),
                                 map<string, int>());

    else if (type == "clothes")
        return new clothesShop("newClothesshop", 7, "clothes", "2021-01-01", 0, 0, list<ShopRemark *>(),
                               map<string, int>());

    else if (type == "stationery")
        return new stationeryShop("newStationeryshop", 8, "stationery", "2021-01-01", 0, 0, list<ShopRemark *>(),
                                  map<string, int>());

    else if (type == "sport")
        return new sportShop("newSportshop", 9, "sport", "2021-01-01", 0, 0, list<ShopRemark *>(), map<string, int>());

    return nullptr;
}

Shop *shopInterface::createShop(string type) {
    Shop *new_shop = _shopFactory.createShop(type);
    return new_shop;
}

void shopInterface::showAllShops() {
    for (auto _shop:_shopList) {
        filterVisitor.visit(_shop);
    }
}

void shopInterface::checkShop(int ID) {
    for (auto _shop:_shopList) {
        if (_shop->getShopId() == ID) {
            infoVisitor.visit(_shop);
            return;
        }
    }
    cout << "No such ID shop." << endl;
}

void shopInterface::editStorage(int ID) {
    for (auto _shop : _shopList) {
        if (ID == _shop->getShopId()) {
            cout << "请修改本店库存：" << endl;
            int new_storage;
            cin >> new_storage;
            _shop->setShopStorage(new_storage);
            return;
        }
    }
    cout << "未知的店铺ID" << endl;
}

void shopInterface::initialize() {
    ShopRemark *defaultRemark = new ShopRemark("2021-01-01", "Administrator", "Good.", 5);
    list<ShopRemark *> defaultRemarkList;
    defaultRemarkList.push_back(defaultRemark);
    map<string, int> defaultGoodsList;
    //TODO:
    defaultGoodsList["testItem"] += 10;
    _shopList.push_back(
            new foodShop("芜湖肉蛋葱鸡专营店", 1, "food", "2013-09-18", 10029, 0, defaultRemarkList, defaultGoodsList));
    _shopList.push_back(
            new drinkShop("芜湖美汁汁儿专营店", 2, "drink", "2013-09-18", 4396, 0, defaultRemarkList, defaultGoodsList));
    _shopList.push_back(
            new digitalShop("芜湖外设专营店", 3, "digital", "2013-09-18", 4396, 0, defaultRemarkList, defaultGoodsList));
    _shopList.push_back(
            new bookShop("芜湖杀人书专营店", 4, "book", "2013-09-18", 4396, 0, defaultRemarkList, defaultGoodsList));
    _shopList.push_back(
            new dailyShop("芜湖日用品专营店", 5, "daily", "2013-09-18", 4396, 0, defaultRemarkList, defaultGoodsList));
    _shopList.push_back(
            new furnitureShop("芜湖厨具专营店", 6, "furniture", "2013-09-18", 4396, 0, defaultRemarkList, defaultGoodsList));
    _shopList.push_back(
            new clothesShop("芜湖发病棉袄专营店", 7, "clothes", "2004-12-01", 2912, 0, defaultRemarkList, defaultGoodsList));
    _shopList.push_back(
            new stationeryShop("芜湖文具专营店", 8, "stationery", "2013-09-18", 4396, 0, defaultRemarkList, defaultGoodsList));
    _shopList.push_back(
            new sportShop("芜湖运动设备专营店", 9, "sport", "2013-09-18", 4598, 0, defaultRemarkList, defaultGoodsList));
    _shopList.push_back(new nullShop("", 0, "", "", 0, 0, defaultRemarkList, defaultGoodsList));
}

void shopInterface::addRemark(int ID) {
    for (auto _shop:_shopList) {
        if (ID == _shop->getShopId()) {
            string _remarkDate, _remarkBody;
            int _remarkScore;
            cout << "Please add your remark date,remark user and remark score here:" << endl;
            cin.ignore();
            getline(cin, _remarkDate);
            getline(cin, _remarkBody);
            cin >> _remarkScore;
            _shop->addShopRemarks(_remarkDate, "User", _remarkBody, _remarkScore);
            return;
        }
    }
    cout << "Invalid ID." << endl;
}

void shopInterface::filterShopByScore() {

    list<Shop *> shoplistHigh;
    list<Shop *> shoplistMid;
    list<Shop *> shoplistLow;

    HighShopFilter highShopFilter;
    shoplistHigh = highShopFilter.selectShop(_shopList);

    MidShopFilter midShopFilter;
    shoplistMid = midShopFilter.selectShop(_shopList);

    LowShopFilter lowShopFilter;
    shoplistLow = lowShopFilter.selectShop(_shopList);

    cout << "High Score Shops:" << shoplistHigh.size() << endl;
    for (auto _shop:shoplistHigh) {
        filterVisitor.visit(_shop);
    }
    cout << endl;

    cout << "Mid Score Shops:" << shoplistMid.size() << endl;
    for (auto _shop:shoplistMid) {
        filterVisitor.visit(_shop);
    }
    cout << endl;

    cout << "Low Score Shops:" << shoplistLow.size() << endl;
    for (auto _shop:shoplistLow) {
        filterVisitor.visit(_shop);
    }
    cout << endl;
}

void shopInterface::manageGoods(int ID) {
    map<string, int> _tempList;
    string _item;
    int _changeNum;
    cin >> _item;
    cin >> _changeNum;//>0 add, <0 minus;
    for (auto _shop:_shopList) {
        if (_shop->getShopId() == ID) {
            _tempList = _shop->getItemList();
            _tempList[_item] += _changeNum;
            _shop->setItemList(_tempList);
        }
    }

}

void shopInterface::showAllGoodsInShops() {
    for (Shop *_shop:_shopList) {
        cout << "Shop: " << _shop->getShopName() << endl;
        cout << "Shop Menu:" << endl;
        for (auto _metaItem:_shop->getItemList()) {
            cout << _metaItem.first << ": " << _metaItem.second << endl;
        }
        cout << endl;
    }
    return;
}

void shopInterface::checkGoods(int ID) {
    for (Shop *_shop:_shopList) {
        if (_shop->getShopId() == ID) {
            for (auto _metaItem:_shop->getItemList()) {
                cout << _metaItem.first << ": " << _metaItem.second << endl;
            }
        }
        cout << endl;
    }
    return;
}

void shopInterface::mainInterface() {
    int choice_status;
    int ID;
    initialize();
    while (1) {
        cout << "-- Welcome to Explore SHOPS in TMALL 11.11! --" << endl;
        cin >> choice_status;
        if (choice_status == 0)
            break;
        switch (choice_status) {
            case 1:
                showAllShops();
                break;
            case 2: {
                cin >> ID;
                addRemark(ID);
                break;
            }
            case 3: {
                filterShopByScore();
                break;
            }
            case 4: {
                cin >> ID;
                checkShop(ID);
                break;
            }
            case 5: {
                cin >> ID;
                manageGoods(ID);
                break;
            }

            case 6: {
                showAllGoodsInShops();
                break;
            }

            default:
                cout << "input again!" << endl;
                break;
        }
    }
}
