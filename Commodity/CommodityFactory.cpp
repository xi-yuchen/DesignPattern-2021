//
// Created by liruijie666 on 2021/10/30.
//
#include "CommodityFactory.h"

using namespace std;

/*
 * Flyweight设计模式
 *      工厂在生成对象的时候优先检查哈希表里有没有，有的话直接调用该对象，没有的话再重新生成。
 *      可以大大减少内存的使用，提高运行效率。
 */
CommodityInformation * CommodityFactory::getSingleCommodity(int ID, string name, int price, int shopID, int amount) {
    for (auto iter:_existingCommodityList) {
        reader.setCommodityInformation(iter.first);
        if (reader.getID() == ID)
            return iter.first;
        else
            continue;
    }
    SingleCommodity *singleCommodity = new SingleCommodity(ID, name, price, shopID, amount);
    _existingCommodityList[singleCommodity]++;
    return singleCommodity;
}
