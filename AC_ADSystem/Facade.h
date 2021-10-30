#pragma once
#include <vector>
#include <map>
#include <string>
#include "Commodity.h"
using namespace std;

//使用设计模式：外观模式、解释器

class AdvertisingSystem;
class ActivitySystem;
class Interpreter;

class Facade//外观模式
{
public:

    Facade();//构造广告子系统、活动子系统、解释器

    // Ad
    void BrowseAd();//浏览全部广告
    void BrowseAd(int BrowseAdID);//浏览单个广告
    void AddAd(int ID, string Cont);//添加单个广告

    //Ac
    void BrowseAc();
    void BrowseAc(int BrowseAcID);
    void AddAcD(int ID, string Cont, vector<int>& CommodityInformationReaderList, float DisRate);//添加打折类活动
    void AddAcF(int ID, string Cont, float Thd, float RedAmount);//添加满减类活动

    float CalOptimalDecision(map<CommodityInformation*, int>& BuyCommodityInformationReaderMap);//寻求最优惠价格，并打印此时活动列表
    void RecommendActivity(vector<CommodityInformation*>& RelatedCommodityInformationReaderList);//打印与商品相关的所有活动
    void RecommendActivity(map<CommodityInformation*, int>& RelatedCommodityInformationReaderMap);//打印与商品相关的所有活动

private:
    
    AdvertisingSystem* AdSystemInstance;
    ActivitySystem* AcSystemInstance;
    Interpreter* ActivityInterpreter;
};

