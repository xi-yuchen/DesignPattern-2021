#pragma once
#include <string>
#include <iostream>
using namespace std;

//使用设计模式：模板模式、访问者模式、迭代器

class AdvertisingSystem;

class AdVisitor//广告visitor父类
{
public:

    virtual ~AdVisitor() = default;

    virtual void Visit(AdvertisingSystem* AdSystem) = 0;
};

class AdVisitor_Browse : public AdVisitor//浏览广告visitor子类
{
public:

    AdVisitor_Browse();//浏览全部广告
    AdVisitor_Browse(int BrowseID);//浏览单个广告

    void Visit(AdvertisingSystem* AdSystem) override;
    

private:

    int BrowseAdID = -1;
};

class AdVisitor_Add : public AdVisitor//添加广告visitor子类
{
public:

    AdVisitor_Add(int ID, string Cont);//添加单个广告
    
    void Visit(AdvertisingSystem* AdSystem) override;

private:

    int AdID;
    string Content;
};
