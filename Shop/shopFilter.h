//
// Created by Hayasaka Ai on 2021/10/29.
//

#ifndef TEST_SHOPFILTER_H
#define TEST_SHOPFILTER_H

#include<iostream>
#include<list>
#include "shop.h"

/*
 * 设计模式：过滤器模式 Filter Mode
 * ShopFilter是店铺过滤器的基类，三个派生类分别根据评分进行对应的操作
 * 我设置的评分标准为：
 *      如果Shop中的score >= 7.5, 将之加入高分过滤器的列表中；
 *      类似, 中分过滤器为 5<=score<7.5，低分过滤器为2.5<=score<5.
 * 在每个过滤器的子类中都有一个函数：
 *      selectShop(): 参数为本程序中拥有的所有店铺的列表，即对其中的所有店铺根据上述标准进行筛选。
 *      该函数最终会返回一个筛选完成的列表供其他子系统模块调用。
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
