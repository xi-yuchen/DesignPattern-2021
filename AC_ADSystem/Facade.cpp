#include "Facade.h"

#include "ActivitySystem.h"
#include "AdvertisingSystem.h"
#include "AdVisitor.h"
#include "AcVisitor.h"
#include "Interpreter.h"

Facade::Facade()
{
    AdSystemInstance = AdvertisingSystem::GetAdSystemInstance();
    AcSystemInstance = ActivitySystem::GetAcSystemInstance();
    ActivityInterpreter = new Interpreter();

    AddAd(1, "手机双11冰点价，买立返红包!");//添加广告
    AddAd(2, "我们的目标是：不愁货——有！不愁钱——折！不愁人——我们都在!");//添加广告
    AddAd(3, "双11百亿元品牌优惠券，11月11日折后再优惠，马上就抢!");//添加广告
    AddAd(4, "天生我才必有用，有用用在双十一！");//添加广告
    AddAd(5, "说好的双11，说好的目标，加油!");//添加广告
    AddAd(6, "买了我的壁纸，才证明你有房子!");//添加广告
    AddAd(7, "话说我们要把1111当天的纯利润全部捐于贫困山区!");//添加广告
    AddAd(8, "让性感的衣服投进您温柔的怀抱！从上到下，抚摸您的每一寸肌肤！");//添加广告
    AddAd(9, "双11来临，你脱光了吗，双11来了，双十二还会远吗，双11 来了，你还在等神马？!");//添加广告
    AddAd(10, "双十一“没门”？怎么能没门！买东西我放心，没门变有门！");//添加广告


    vector<int> vect1;//商品列表
    vect1.push_back(11);
    vect1.push_back(12);
    vect1.push_back(13);
    vect1.push_back(14);
    vect1.push_back(15);
    AddAcD(1, "服饰商品全场八折！", vect1, 0.8);//添加打折类活动
    vector<int> vect2;//商品列表
    vect2.push_back(21);
    vect2.push_back(22);
    vect2.push_back(23);
    vect2.push_back(24);
    vect2.push_back(25);
    AddAcD(2, "零食生鲜全场七五折！", vect2, 0.75);//添加打折类活动
    vector<int> vect3;//商品列表
    vect3.push_back(31);
    vect3.push_back(32);
    vect3.push_back(33);
    vect3.push_back(34);
    vect3.push_back(35);
    AddAcD(3, "珠宝饰品全场九五折！", vect3, 0.95);//添加打折类活动
    vector<int> vect4;//商品列表
    vect4.push_back(41);
    vect4.push_back(42);
    vect4.push_back(43);
    vect4.push_back(44);
    vect4.push_back(45);
    AddAcD(4, "母婴用品全场七折！", vect4, 0.7);//添加打折类活动
    vector<int> vect5;//商品列表
    vect5.push_back(51);
    vect5.push_back(52);
    vect5.push_back(53);
    vect5.push_back(54);
    vect5.push_back(55);
    AddAcD(5, "医护用品全场五折！", vect5, 0.5);//添加打折类活动

    AddAcF(1, "全场满100减15", 100, 15);//添加满减类活动
    AddAcF(2, "全场满500减100", 500, 100);//添加满减类活动
    AddAcF(3, "全场满1000减250", 1000, 250);//添加满减类活动

}

void Facade::BrowseAd()
{
    AdVisitor_Browse* AdBrowse = new AdVisitor_Browse();
    AdSystemInstance->Accept(AdBrowse);

    delete AdBrowse;
}

void Facade::BrowseAd(int BrowseAdID)
{
    AdVisitor_Browse* AdBrowse = new AdVisitor_Browse(BrowseAdID);
    AdSystemInstance->Accept(AdBrowse);

    delete AdBrowse;
}

void Facade::AddAd(int ID, string Cont)
{
    AdVisitor_Add* AddAdVisit = new AdVisitor_Add(ID, Cont);
    AdSystemInstance->Accept(AddAdVisit);
    delete AddAdVisit;
}

void Facade::BrowseAc()
{
    AcVisitor_Browse* AcBrowse = new AcVisitor_Browse();
    AcSystemInstance->Accept(AcBrowse);

    delete AcBrowse;
}

void Facade::BrowseAc(int BrowseAcID)
{
    AcVisitor_Browse* AcBrowse = new AcVisitor_Browse(BrowseAcID);
    AcSystemInstance->Accept(AcBrowse);

    delete AcBrowse;
}

void Facade::AddAcD(int ID, string Cont, vector<int>& CommodityInformaitonReaderList, float DisRate)
{
    AcVisitor_Add* AddAcVisit = new AcVisitor_Add(ID, Cont, CommodityInformaitonReaderList, DisRate);
    AcSystemInstance->Accept(AddAcVisit);
    delete AddAcVisit;
}

void Facade::AddAcF(int ID, string Cont, float Thd, float RedAmount)
{
    AcVisitor_Add* AddAcVisit = new AcVisitor_Add(ID, Cont, Thd, RedAmount);
    AcSystemInstance->Accept(AddAcVisit);
    delete AddAcVisit;
}

float Facade::CalOptimalDecision(map<CommodityInformaitonReader*, int>& BuyCommodityInformaitonReaderMap) // 策略模式
{
    AcVisitor_CalPrice* CalPriceVisitor;

    CalPriceVisitor = new AcVisitor_CP_Discount(BuyCommodityInformaitonReaderMap); // 策略1，使用打折活动
    AcSystemInstance->Accept(CalPriceVisitor);
    float OptimalPrice = CalPriceVisitor->OptimalPrice;
    string OptimalDecisionCode = CalPriceVisitor->OptimalDecisionCode;

    delete CalPriceVisitor;

    CalPriceVisitor = new AcVisitor_CP_FullRedu(BuyCommodityInformaitonReaderMap); // 策略2，使用满减活动
    AcSystemInstance->Accept(CalPriceVisitor);
    if (CalPriceVisitor->OptimalPrice < OptimalPrice)
    {
        OptimalPrice = CalPriceVisitor->OptimalPrice;
        OptimalDecisionCode = CalPriceVisitor->OptimalDecisionCode;
    }

    ActivityInterpreter->MakeInterpretation(OptimalDecisionCode); // 进行解释

    cout << "###最优价格为： " << OptimalPrice << endl;
    return OptimalPrice;
}

void Facade::RecommendActivity(vector<CommodityInformaitonReader*>& RelatedCommodityInformaitonReaderList)
{
    AcVisitor_Recommend* RecommendVisitor = new AcVisitor_Recommend(RelatedCommodityInformaitonReaderList); // 寻找相关活动

    AcSystemInstance->Accept(RecommendVisitor);
    ActivityInterpreter->MakeInterpretation(RecommendVisitor->RecommendActivityCode); // 进行解释

    delete RecommendVisitor;
}

void Facade::RecommendActivity(map<CommodityInformaitonReader*, int>& RelatedCommodityInformaitonReaderMap)
{
    vector<CommodityInformaitonReader*> RelatedCommodityInformaitonReaderList;
    for (auto it = RelatedCommodityInformaitonReaderMap.begin(); it != RelatedCommodityInformaitonReaderMap.end(); it++)
    {
        RelatedCommodityInformaitonReaderList.push_back((*it).first);
    }
    RecommendActivity(RelatedCommodityInformaitonReaderList);
}
