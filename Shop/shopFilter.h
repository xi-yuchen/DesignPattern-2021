//
// Created by Hayasaka Ai on 2021/10/29.
//

#ifndef TEST_SHOPFILTER_H
#define TEST_SHOPFILTER_H

#include<iostream>
#include<list>
#include "shop.h"

/*
 * DesignPattern - 'Filter Mode'
 * The ShopFilter class is used to identify all shops by the remark score.
 *      if the score >= 7.5, it's a high-score shop and added to a high-score list.
 *      Like this, mid-score is 5<=score<7.5 and low-score is 2.5<=score<5.
 * In each filter class, there is a function:
 *      selectShop(): The only argument is the list of all shops. The three filter classes will add
 *                    suitable shop to their list according to the remark score.
 * At last, these three classes will have three list of high, mid and low score shops as a result.
 */
class ShopFilter {
public:
    //Define as an abstract class and functions.
    virtual list<Shop *> selectShop(list<Shop *> ShopList) = 0;
};

class HighShopFilter:public ShopFilter{
public:
    list<Shop *> selectShop(list<Shop *> ShopList);
};

class MidShopFilter:public ShopFilter{
public:
    list<Shop *> selectShop(list<Shop *> ShopList);
};

class LowShopFilter:public ShopFilter{
public:
    list<Shop *> selectShop(list<Shop *> ShopList);
};
#endif //TEST_SHOPFILTER_H
