#include "shopInterface.h"
#include <string>
#include <ctime>
#include"../Customer/Customers.h"
#include"../Customer/Customer.h"

/*
 * 预先声明Visitor以供后续使用，因为派生类也在这里定义，无法同时定义和声明，所以在此预先声明
 */
infoVisitor infoVisitor;
filterVisitor filterVisitor;


/*
 * 设计模式-空项目模式 Null Object Mode
 * 实际使用中，用户很有可能会忘记输入参数，所以可能给函数传空值或null值
 * 为了程序健壮性和功能完整性，可以使用空项目模式：
 *      在函数运行中预先对参数为空或null做判断，如果为真则也生成一个对象，但是对象中的值都是没有意义的值。而非给用户只输出错误信息。
 *      这样做无论什么情况都可以按照生成对象的标准化来处理。
 */

/*
 * 设计模式 - 代理模式 Proxy Mode
 * 用一个对象包含一个同等的对象，即可以包含的对象为代理，对被包含的对象进行操作。
 * 代理对象拥有被包含对象所有的操作和属性，还额外包含了被包含对象的属性。
 * 对代理对象进行的操作可以等效于直接对包含对象进行操作，此处操作为输出店铺的信息。
 */

// 其中包含生成空对象和代理对象的对应操作
Shop *ShopFactory::createShop(string type) {
    if (type == "")
        return new nullShop("unknown", rand() % 10000 + 10, "unknown", "2021-01-01", 0, 0, list<ShopRemark *>(),
                            map<CommodityInformation *, int>());

    else if (type == "food")
        return new foodShop("newFoodshop", rand() % 10000 + 10, "food", "2021-01-01", 0, 0, list<ShopRemark *>(),
                            map<CommodityInformation *, int>());

    else if (type == "drink")
        return new drinkShop("newDrinkshop", rand() % 10000 + 10, "drink", "2021-01-01", 0, 0, list<ShopRemark *>(),
                             map<CommodityInformation *, int>());

    else if (type == "digital")
        return new digitalShop("newDigitalshop", rand() % 10000 + 10, "digital", "2021-01-01", 0, 0,
                               list<ShopRemark *>(),
                               map<CommodityInformation *, int>());

    else if (type == "book")
        return new bookShop("newBookshop", rand() % 10000 + 10, "book", "2021-01-01", 0, 0, list<ShopRemark *>(),
                            map<CommodityInformation *, int>());

    else if (type == "daily")
        return new dailyShop("newDailyshop", rand() % 10000 + 10, "daily", "2021-01-01", 0, 0, list<ShopRemark *>(),
                             map<CommodityInformation *, int>());

    else if (type == "furniture")
        return new furnitureShop("newFurnitureshop", rand() % 10000 + 10, "furniture", "2021-01-01", 0, 0,
                                 list<ShopRemark *>(),
                                 map<CommodityInformation *, int>());

    else if (type == "clothes")
        return new clothesShop("newClothesshop", rand() % 10000 + 10, "clothes", "2021-01-01", 0, 0,
                               list<ShopRemark *>(),
                               map<CommodityInformation *, int>());

    else if (type == "stationery")
        return new stationeryShop("newStationeryshop", rand() % 10000 + 10, "stationery", "2021-01-01", 0, 0,
                                  list<ShopRemark *>(),
                                  map<CommodityInformation *, int>());

    else if (type == "sport")
        return new sportShop("newSportshop", rand() % 10000 + 10, "sport", "2021-01-01", 0, 0, list<ShopRemark *>(),
                             map<CommodityInformation *, int>());

    else if (type == "proxy")
        return new proxyShop("unknown", rand() % 10000 + 10, "unknown", "2021-01-01", 0, 0, list<ShopRemark *>(),
                             map<CommodityInformation *, int>(), nullptr);

    //非上述情况时，制造不出有意义的值，所以停止制造即可。
    return nullptr;
}

/*
 * 工厂模式创建店铺函数的具体实现
 */
Shop *shopInterface::createShop(string type) {
    Shop *new_shop = _shopFactory.createShop(type);
    _shopList.push_back(new_shop);
    return new_shop;
}

/*
 * 店铺整合接口类
 * 利用Visitor模式过滤店铺函数的具体实现
 */
void shopInterface::showAllShops() {
    for (auto _shop:_shopList) {
        filterVisitor.visit(_shop);
    }
}

/*
 * 店铺整合接口类
 * 利用Visitor模式查看指定ID店铺信息的具体实现
 */
void shopInterface::checkShop(int ID) {
    for (auto _shop:_shopList) {
        if (_shop->getShopId() == ID) {
            infoVisitor.visit(_shop);
            return;
        }
    }
    cout << "未知的店铺ID！" << endl;
}

/*
 * 店铺整合接口类
 * 预先生成10个店铺并初始化所有店铺数据；
 */
void shopInterface::initialize() {
    ShopRemark *defaultRemark = new ShopRemark("2021-01-01", "Administrator", "Good.", 5);
    list<ShopRemark *> defaultRemarkList;
    defaultRemarkList.push_back(defaultRemark);
    ShopFactory shopFactory;
    map<CommodityInformation *, int> defaultGoodsList;
    _shopList.push_back(
            new foodShop("芜湖肉蛋葱鸡专营店", 1, "food", "2013-09-18", 0, 0, defaultRemarkList, defaultGoodsList));
    _shopList.push_back(
            new drinkShop("芜湖美汁汁儿专营店", 2, "drink", "2013-09-18", 0, 0, defaultRemarkList, defaultGoodsList));
    _shopList.push_back(
            new digitalShop("芜湖外设专营店", 3, "digital", "2013-09-18", 0, 0, defaultRemarkList, defaultGoodsList));
    _shopList.push_back(
            new bookShop("芜湖杀人书专营店", 4, "book", "2013-09-18", 0, 0, defaultRemarkList, defaultGoodsList));
    _shopList.push_back(
            new dailyShop("芜湖日用品专营店", 5, "daily", "2013-09-18", 0, 0, defaultRemarkList, defaultGoodsList));
    _shopList.push_back(
            new furnitureShop("芜湖厨具专营店", 6, "furniture", "2013-09-18", 0, 0, defaultRemarkList, defaultGoodsList));
    _shopList.push_back(
            new clothesShop("芜湖发病棉袄专营店", 7, "clothes", "2004-12-01", 0, 0, defaultRemarkList, defaultGoodsList));
    _shopList.push_back(
            new stationeryShop("芜湖文具专营店", 8, "stationery", "2013-09-18", 0, 0, defaultRemarkList, defaultGoodsList));
    _shopList.push_back(
            new sportShop("芜湖运动设备专营店", 9, "sport", "2013-09-18", 0, 0, defaultRemarkList, defaultGoodsList));
    _shopList.push_back(new nullShop("", 0, "", "", 0, 0, defaultRemarkList, defaultGoodsList));
}

/*
 * 店铺整合接口类
 * 顾客向指定ID的店铺添加评论：只需要输入评论内容和评价分数即可，评论时间系统自动生成；
 * 如果找不到对应ID的店铺，就输出错误信息，然后退出函数即可。
 */
void shopInterface::addRemark(int ID, Customer *customer) {
    VirtualCustomerInformationReader *reader = customer->getCustomerReader();
    time_t t = time(0);
    char ch[64];
    strftime(ch, sizeof(ch), "%Y-%m-%d %H:%M:%S", localtime(&t));
    for (auto _shop:_shopList) {
        if (ID == _shop->getShopId()) {
            string _remarkDate, _remarkBody;
            int _remarkScore;
            cout << "请输入您的评价内容与评分:" << endl;
            cin.ignore();
            _remarkDate.assign(ch + 2);
            getline(cin, _remarkBody);
            cin >> _remarkScore;
            _shop->addShopRemarks(_remarkDate, reader->getName(), _remarkBody, _remarkScore);
            return;
        }
    }
    cout << "该店铺ID不存在." << endl;
}

/*
 * 店铺整合接口类
 * 根据店铺评分过滤店铺函数：根据上一个写评论函数的功能里“添加评分”这一个属性值，可以根据评分函数来将之添加到不同类对应的结果数据集中
 *      在定义中筛选和评分的标准已经说得比较清楚，此处不再赘述。
 */
void shopInterface::filterShopByScore() {

    // 这里有3个结果集，分别是根据标准函数筛选之后盛放结果的集合。
    list<Shop *> shoplistHigh;
    list<Shop *> shoplistMid;
    list<Shop *> shoplistLow;

    // 高分，按照高分的判断标准和函数来处理。
    HighShopFilter highShopFilter;
    shoplistHigh = highShopFilter.selectShop(_shopList);

    // 中分，按照中分的判断标准和函数来处理。
    MidShopFilter midShopFilter;
    shoplistMid = midShopFilter.selectShop(_shopList);

    // 低分，按照低分的判断标准和函数来处理。
    LowShopFilter lowShopFilter;
    shoplistLow = lowShopFilter.selectShop(_shopList);

    // 结果集处理到位以后，输出对应的店铺即可，输出仍然有Visitor模式，不影响数据和操作
    cout << "高分店铺: " << shoplistHigh.size() << endl;
    for (auto _shop:shoplistHigh) {
        filterVisitor.visit(_shop);
    }
    cout << endl;

    cout << "中分店铺: " << shoplistMid.size() << endl;
    for (auto _shop:shoplistMid) {
        filterVisitor.visit(_shop);
    }
    cout << endl;

    cout << "低分店铺: " << shoplistLow.size() << endl;
    for (auto _shop:shoplistLow) {
        filterVisitor.visit(_shop);
    }
    cout << endl;
}

/*
 * 店铺整合接口类
 * 展示所有店铺内所有货物的函数：遍历店铺，输出每个店铺的货物单的内容
 * 其在店铺类的对应属性中都有定义。
 */
void shopInterface::showAllGoodsInShops() {
    CommodityInformationReader reader;
    for (Shop *_shop:_shopList) {
        cout << "店铺: " << _shop->getShopName() << endl;
        cout << "货品菜单: " << endl;
        for (const auto &_metaItem:_shop->getItemList()) {
            reader.setCommodityInformation(_metaItem.first);
            cout << reader.getName() << " - ￥" << reader.getPrice() << endl;
        }
        cout << endl;
    }
}

/*
 * 店铺整合接口类
 * 查看指定ID店铺中的货物函数：遍历整个店铺列表，如果找到ID与指定ID相等的店铺，输出其货物单中内容即可。
 *      如果没找到，输出提示信息后返回。
 */
void shopInterface::checkGoods(int ID) {
    CommodityInformationReader reader;
    for (Shop *_shop:_shopList) {
        if (_shop->getShopId() == ID) {
            cout << "店铺: " << _shop->getShopName() << endl;
            cout << "货品菜单: " << endl;
            cout << "商品ID - 名称 - 价格" << endl;
            for (const auto &_metaItem:_shop->getItemList()) {
                reader.setCommodityInformation(_metaItem.first);
                cout << reader.getID() << " - " << reader.getName() << " - ￥" << reader.getPrice() << endl;
            }
            cout << endl;
            return;
        } else
            continue;
    }
    cout << "您输入的店铺ID不存在！" << endl;
}

/*
 * 店铺整合接口类
 * 备货函数：一开始创建的店铺里面货物是空的，需要把货物对应到各自所属的店铺去
 *      对整体的货物列表遍历，如果有货物的ID与参数中店铺ID一致，即可加入该店铺，最终对所有店铺都执行这个函数即可。
 */
void shopInterface::prepareGoods(int ID) {
    CommodityInformationReader reader;
    map<CommodityInformation *, int> _tempCommodityList;
    for (Shop *_shop:_shopList) {
        if (_shop->getShopId() == ID) {
            for (auto _tempCommodity:getCommodityList()) {
                reader.setCommodityInformation(_tempCommodity.first);
                if (reader.getShopID() == ID) {
                    _tempCommodityList[_tempCommodity.first] = ID;
                    _shop->setItemList(_tempCommodityList);
                }
            }
        }
    }
}

/*
 * 店铺整合接口类
 * 展示货物列表函数：对某商店的货物列表进行遍历，输出其部分信息（此处为商品ID、商品名称和商品价格），每输出10个换一行。
 * 没有也没关系，会输出对应的提示信息。
 */
void shopInterface::showCommodityList(map<CommodityInformation *, int> _List) {
    CommodityInformationReader reader;
    int _rowIndex = 0;
    if (_List.empty()) {
        cout << "该店铺暂无商品！" << endl;
        return;
    }
    for (auto _commodity:_List) {
        reader.setCommodityInformation(_commodity.first);
        cout << reader.getID() << "-" << reader.getName() << "-￥" << reader.getPrice() << " ";
        _rowIndex++;
        if (_rowIndex == 10) {
            cout << endl;
            _rowIndex = 0;
        }
    }
}

/*
 * 店铺整合接口类
 * 在所有货物列表中查找对应ID的货物，如果找到了返回该商品的信息
 *      如果找不到则返回空指针。
 */
CommodityInformation *shopInterface::addCart(int ID) {
    CommodityInformationReader reader;
    for (auto _commodity:_commodityList) {
        reader.setCommodityInformation(_commodity.first);
        if (reader.getID() == ID)
            return _commodity.first;
    }
    return nullptr;
}

/*
 * 店铺整合接口类
 * 主函数：整合了之前所定义和声明的所有的函数
 *      输入对应的选项即可执行其对应的功能
 */
void shopInterface::mainInterface(Customer *customer) {
    // 先备货
    for (int i = 1; i <= 9; i++)
        prepareGoods(i);
    showUserShopCmds showUserShopCmds;
    //选项和ID的执行，这是主函数的具体执行，实际上就是根据choice_status来调用之前所说过的函数，此处不再赘述。
    int choice_status, ID;
    while (true) {
        showUserShopCmds.showUserCmds();
        cin >> choice_status;
        if (choice_status == 0)
            break;
        switch (choice_status) {
            case 1:
                showAllShops();
                break;
            case 2: {
                cout << "请输入您要评价的店铺: " << endl;
                cin >> ID;
                addRemark(ID, customer);
                break;
            }
            case 3: {
                filterShopByScore();
                break;
            }
            case 4: {
                cout << "请输入您要查看详细信息的店铺ID: " << endl;
                cin >> ID;
                checkShop(ID);
                break;
            }
            case 5: {
                showAllGoodsInShops();
                break;
            }
            case 6: {
                cout << "请输入您要查看货物列表的店铺ID: " << endl;
                cin >> ID;
                checkGoods(ID);
                break;
            }
            default:
                cout << "不存在的命令！请重新输入！" << endl;
                break;
        }
    }
}


