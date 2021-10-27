#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

//使用设计模式：模板模式、访问者模式、迭代器

class CommodityInformaitonReader;

enum ActivityType//活动类型
{
    Discount,//打折类活动
    FullReduction,//满减类活动
};

class ActivitySystem;

class AcVisitor//活动Visitor父类
{
public:
    virtual ~AcVisitor() = default;
    virtual void Visit(ActivitySystem* AcSystem) = 0;
};

class AcVisitor_Recommend : public AcVisitor//推荐活动Visitor子类
{
public:

    AcVisitor_Recommend(vector<CommodityInformaitonReader*>& RelatedCommodityInformaitonReaderList);//推荐商品相关活动

    void Visit(ActivitySystem* AcSystem) override;

    string RecommendActivityCode;

private:

    vector<CommodityInformaitonReader*> SaveRelatedCommodityInformaitonReaderList;

};

class AcVisitor_CalPrice : public AcVisitor//计算最优活动Visitor子类
{
public:

    AcVisitor_CalPrice(map<CommodityInformaitonReader*, int>& BuyCommodityInformaitonReaderMap);//计算商品对应的最优惠活动组合即价格

    float OptimalPrice; // 计算结果
    string OptimalDecisionCode; // 计算结果

protected:

    map<CommodityInformaitonReader*, int> SaveBuyCommodityInformaitonReaderMap;
};

class AcVisitor_CP_Discount : public AcVisitor_CalPrice//计算最优打折活动Visitor子类
{
public:

    AcVisitor_CP_Discount(map<CommodityInformaitonReader*, int>& BuyCommodityInformaitonReaderMap);//计算打折活动的最优惠活动组合

    void Visit(ActivitySystem* AcSystem) override;
};

class AcVisitor_CP_FullRedu : public AcVisitor_CalPrice//计算最优满减活动Visitor子类
{
public:

    AcVisitor_CP_FullRedu(map<CommodityInformaitonReader*, int>& BuyCommodityInformaitonReaderMap);//计算满减活动的最优惠活动组合

    void Visit(ActivitySystem* AcSystem) override;
};

class AcVisitor_Browse : public AcVisitor//浏览活动Visitor子类
{
public:

    AcVisitor_Browse();//浏览全部活动
    AcVisitor_Browse(int BrowseID);//浏览单个活动

    void Visit(ActivitySystem* AdSystem) override;
    
private:

    int BrowseAcID = -1;
};

class AcVisitor_Add : public AcVisitor//添加活动Visitor子类
{
public:

    AcVisitor_Add(int ID, string Cont, vector<int>& CommodityInformaitonReaderList, float DisRate);//添加打折类活动
    AcVisitor_Add(int ID, string Cont, float Thd, float RedAmount);//添加满减类活动

    void Visit(ActivitySystem* AcSystem) override;

private:

    ActivityType AcType;

    int AcID;
    string Content;
    
    vector<int> SatisfyCommodityInformaitonReaderIDList;
    float DiscountRate;

    float Threshold;
    float ReductionAmount;
};
