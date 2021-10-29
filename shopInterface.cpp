#include "shopInterface.h"

Shop* ShopFactory::createShop(string type) {
    if (type == "")
        return new nullShop("暂无", 
                            0,
                            "暂无",
                            "暂无", 
                            0,
                            list<ShopRemark*>());
    
    else if (type == "food")
        return new foodShop("芜湖大司马肉蛋葱鸡专营店",
            2,
            "food",
            "2013-09-18",
            10029,
            list<ShopRemark*>());
    
    else if (type == "clothes")
        return new clothesShop("芜湖发病棉袄自营旗舰店",
            192,
            "clothes",
            "2004-12-01",
            2912,
            list<ShopRemark*>());
    
}

void shopInterface::showAllShops() {
    for (auto _shop : _shopList) {
        cout << "店名: " << _shop->getShopName() << endl;
        cout << "库存: " << _shop->getShopStorage() << endl << endl;
    }
}

Shop* shopInterface::createShop(string type) {
    Shop* new_shop = _shopFactory.createShop(type);
    return new_shop;
}

void shopInterface::editStorage(int ID) {
    {
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
}

void shopInterface::initialize() {
    _shopList.push_back(new foodShop("芜湖肉蛋葱鸡专营店",
        2,
        "food",
        "2013-09-18",
        10029,
        list<ShopRemark*>()));
    _shopList.push_back(new clothesShop("芜湖发病棉袄专营店",
        192,
        "clothes",
        "2004-12-01",
        2912,
        list<ShopRemark*>()));
}


void shopInterface::mainInterface() {
    int choice_status;
    int ID;
    initialize();
    while (1) {
        cout << "欢迎您！您正在浏览店铺相关信息！" << endl;
        cout << "按1查看所有店铺列表；按2修改店铺库存；按0退出" << endl;
        cin >> choice_status;
        if (choice_status == 0)
            break;
        switch (choice_status) {
        case 1:
            showAllShops();
            break;
        case 2: {
            cout << "请输入您要修改库存的店铺ID！" << endl;
            cin >> ID;
            editStorage(ID);
            break;
        }
        default:
            cout << "未知命令，请重新输入！" << endl;
            break;
        }
    }
}
