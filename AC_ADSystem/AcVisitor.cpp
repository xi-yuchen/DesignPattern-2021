#include "AcVisitor.h"
#include "ActivitySystem.h"
#include "../Commodity/Commodity.h"
#include <set>
#include "../Customer/Customers.h"
#include "../Customer/Customer.h"
AcVisitor_Recommend::AcVisitor_Recommend(vector<CommodityInformation*>& RelatedCommodityInformationList)
{
    for (auto BuyCommodityInformation : RelatedCommodityInformationList)
    {
        SaveRelatedCommodityInformationList.push_back(BuyCommodityInformation);
    }
}

void AcVisitor_Recommend::Visit(ActivitySystem* AcSystem)
{
    string RecommendCode;
    RecommendCode.push_back('2'); // 2代表需要解释的Code为推荐活动列表
    RecommendCode.push_back('-1'); // 与最优活动编码对齐

    set<int> RecommendAcSet;

    for (auto RelatedCommodityInformation : SaveRelatedCommodityInformationList)
    {
        for (int i = 0; i < AcSystem->DiscountActivityList.size(); i++)
        {
            if (AcSystem->DiscountActivityList[i]->IsSatisfy(RelatedCommodityInformation))
                RecommendAcSet.insert(i);
        }
    }

    for (auto Elem : RecommendAcSet)
    {
        RecommendCode.push_back(static_cast<char>(Elem));
    }

    RecommendActivityCode = RecommendCode;
}

AcVisitor_CalPrice::AcVisitor_CalPrice(map<CommodityInformation*, int>& BuyCommodityInformationMap)
{
    for (auto BuyCommodityInformation : BuyCommodityInformationMap)
    {
        SaveBuyCommodityInformationMap.insert(BuyCommodityInformation);
    }
}

AcVisitor_CP_Discount::AcVisitor_CP_Discount(map<CommodityInformation*, int>& BuyCommodityInformationMap) : AcVisitor_CalPrice(BuyCommodityInformationMap)
{
}

void AcVisitor_CP_Discount::Visit(ActivitySystem* AcSystem)
{
    string DecisionCode;
    DecisionCode.push_back('1'); // 1代表需要解释的Code为最优活动列表
    DecisionCode.push_back('1'); // 1代表所选方案为打折活动类

    float TotalMinPrice = 0.0f;
    auto* reader=CustomerSet::getInstance()->getCustomer()->getCommodityReader();
    for (auto BuyCommodityInformation : SaveBuyCommodityInformationMap)
    {
        DecisionCode.push_back(120); // 后续位均代表对应的活动的下标，120即为不使用活动
        reader->setCommodityInformation(BuyCommodityInformation.first);
        float MinPrice = (reader->getPrice()) * BuyCommodityInformation.second;

        for (int i = 0; i < AcSystem->DiscountActivityList.size(); i++)
        {
            float CalPrice = AcSystem->DiscountActivityList[i]->ExecuteActivity(BuyCommodityInformation.first, BuyCommodityInformation.second);
            if (CalPrice < MinPrice)
            {
                MinPrice = CalPrice;
                DecisionCode[DecisionCode.length() - 1] =static_cast<char>(i);
            }
        }

        TotalMinPrice += MinPrice;
    }

    OptimalPrice = TotalMinPrice;
    OptimalDecisionCode = DecisionCode;
}

AcVisitor_CP_FullRedu::AcVisitor_CP_FullRedu(map<CommodityInformation*, int>& BuyCommodityInformationMap) : AcVisitor_CalPrice(BuyCommodityInformationMap)
{
}

void AcVisitor_CP_FullRedu::Visit(ActivitySystem* AcSystem)
{
    string DecisionCode;
    DecisionCode.push_back('1'); // 1代表需要解释的Code为最优活动列表
    DecisionCode.push_back('2'); // 2代表所选方案为满减活动类

    float TotalMinPrice = 0.0f;
    auto* reader=CustomerSet::getInstance()->getCustomer()->getCommodityReader();
    for (auto BuyCommodityInformation : SaveBuyCommodityInformationMap)
    {
        reader->setCommodityInformation(BuyCommodityInformation.first);
        TotalMinPrice += (reader->getPrice()) * BuyCommodityInformation.second;
    }

    DecisionCode.push_back(120); // 后续位均代表对应的活动的下标，120即为不使用活动
    for (int i = 0; i < AcSystem->FullReductionActivityList.size(); i++)
    {
        float CalPrice = AcSystem->FullReductionActivityList[i]->ExecuteActivity(SaveBuyCommodityInformationMap);
        if (CalPrice < TotalMinPrice)
        {
            TotalMinPrice = CalPrice;
            DecisionCode[DecisionCode.length() - 1] = i;
        }
    }

    OptimalPrice = TotalMinPrice;
    OptimalDecisionCode = DecisionCode;
}


AcVisitor_Browse::AcVisitor_Browse()
{
}

AcVisitor_Browse::AcVisitor_Browse(int BrowseID)
{
    BrowseAcID = BrowseID;
}

void AcVisitor_Browse::Visit(ActivitySystem* AcSystem)
{
    if (BrowseAcID == -1)
    {
        for (vector<AcNode_Discount*>::size_type ix = 0; ix != AcSystem->DiscountActivityList.size(); ix++)
        {
            AcSystem->PrintAc_D(ix);
        }
        for (vector<AcNode_FullReduction*>::size_type ix = 0; ix != AcSystem->FullReductionActivityList.size(); ix++)
        {
            AcSystem->PrintAc_F(ix);
        }
        // 迭代器
    }
    else
    {
        int BrowseIndex = 0; // 寻找Index
        int a = 0;
        for (vector<AcNode_Discount*>::iterator iter = AcSystem->DiscountActivityList.begin(); iter != AcSystem->DiscountActivityList.end(); ++iter)
        {
            if ((*iter)->AcID == BrowseAcID)
            {
                a = 1;
                break;
            }
            BrowseIndex++;
        }
        if(a == 1)
            AcSystem->PrintAc_D(BrowseIndex);
        else
        {
            int BrowseIndex = 0;
            for (vector<AcNode_FullReduction*>::iterator iter = AcSystem->FullReductionActivityList.begin(); iter != AcSystem->FullReductionActivityList.end(); ++iter)
            {
                if ((*iter)->AcID == BrowseAcID)
                    break;
                BrowseIndex++;
            }
            AcSystem->PrintAc_F(BrowseIndex);
        }
    }
    // 类似 Ad
}

AcVisitor_Add::AcVisitor_Add(int ID, string Cont, vector<int>& CommodityInformationList, float DisRate)
{
    AcType = ActivityType::Discount;
    AcID = ID;
    Content = Cont;
    SatisfyCommodityInformationIDList = CommodityInformationList;
    DiscountRate = DisRate;
}

AcVisitor_Add::AcVisitor_Add(int ID, string Cont, float Thd, float RedAmount)
{
    AcType = ActivityType::FullReduction;
    AcID = ID;
    Content = Cont;
    Threshold = Thd;
    ReductionAmount = RedAmount;
}

void AcVisitor_Add::Visit(ActivitySystem* AcSystem)
{
    if (AcID < 0)
    {
        cout << "ID < 0 !!!" << endl;
        return;
    }

    if (AcType == ActivityType::Discount)
    {
        AcNode_Discount* ac = new AcNode_Discount(AcID, Content, SatisfyCommodityInformationIDList, DiscountRate);
        AcSystem->DiscountActivityList.push_back(ac);
    }
    else 
    {
        AcNode_FullReduction* ac = new AcNode_FullReduction(AcID, Content, Threshold, ReductionAmount);
        AcSystem->FullReductionActivityList.push_back(ac);
    }

}
