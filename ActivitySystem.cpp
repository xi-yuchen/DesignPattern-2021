#include "ActivitySystem.h"
#include "Commodity.h"
#include "AcVisitor.h"

ActivitySystem* ActivitySystem::AcSystemInstance = nullptr;


AcNode_Discount::AcNode_Discount(int ID, string Cont, vector<int>& CommodityIDList, float DisRate) : AcNode(ID, Cont)
{
    SatisfyCommodityIDList = CommodityIDList;
    DiscountRate = DisRate;
}

float AcNode_Discount::ExecuteActivity(Commodity* BuyCommodity)
{
    if (IsSatisfy(BuyCommodity))
        return CalPrice(BuyCommodity);
    else
        return BuyCommodity->GetPrice();
}

bool AcNode_Discount::IsSatisfy(Commodity* BuyCommodity)
{
    for (vector<int>::iterator iter = SatisfyCommodityIDList.begin(); iter != SatisfyCommodityIDList.end(); ++iter)
    {
        if (BuyCommodity->GetID() == *iter)
            return true;
    }
    return false;
}

float AcNode_Discount::CalPrice(Commodity* BuyCommodity)
{
    return DiscountRate * BuyCommodity->GetPrice();
}

AcNode_FullReduction::AcNode_FullReduction(int ID, string Cont, float Thd, float RedAmount) : AcNode(ID, Cont)
{
    Threshold = Thd;
    ReductionAmount = RedAmount;
}

float AcNode_FullReduction::ExecuteActivity(vector<Commodity*>& BuyCommodity)
{
    if (IsSatisfy(BuyCommodity))
        return CalPrice(BuyCommodity);
    return CalPrice(BuyCommodity) + ReductionAmount;
}

bool AcNode_FullReduction::IsSatisfy(vector<Commodity*>& BuyCommodity)
{
    float sumPrize = 0;
    for (vector<Commodity*>::iterator iter = BuyCommodity.begin(); iter != BuyCommodity.end(); ++iter)
    {
        sumPrize += (*iter)->GetPrice();
    }
    if (sumPrize >= Threshold)
        return true;
    return false;
}

float AcNode_FullReduction::CalPrice(vector<Commodity*>& BuyCommodity)
{
    float sumPrize = 0;
    for (vector<Commodity*>::iterator iter = BuyCommodity.begin(); iter != BuyCommodity.end(); ++iter)
    {
        sumPrize += (*iter)->GetPrice();
    }
    return sumPrize - ReductionAmount;
}

ActivitySystem::~ActivitySystem()
{
    for (auto Elem : DiscountActivityList)
    {
        delete Elem;
    }
    for (auto Elem : FullReductionActivityList)
    {
        delete Elem;
    }
    
    if (AcSystemInstance != nullptr)
        delete AcSystemInstance;
}

ActivitySystem* ActivitySystem::GetAcSystemInstance()
{
    if (AcSystemInstance == nullptr)
        AcSystemInstance = new ActivitySystem;

    return AcSystemInstance;
}

void ActivitySystem::Accept(AcVisitor* Visitor)
{
    Visitor->Visit(this);
}

void ActivitySystem::PrintAc_D(int Index)
{
    int len = DiscountActivityList.size();

    if (Index > len - 1)
        return;

    cout << "Activity ID : " << DiscountActivityList[Index]->AcID << endl;
    cout << "Activity Content : " << DiscountActivityList[Index]->Content << endl;
}

void ActivitySystem::PrintAc_F(int Index)
{
    int len = FullReductionActivityList.size();

    if (Index > len - 1)
        return;

    cout << "Activity ID : " << FullReductionActivityList[Index]->AcID << endl;
    cout << "Activity Content : " << FullReductionActivityList[Index]->Content << endl;
}

ActivitySystem::ActivitySystem()
{
}

AcNode::AcNode(int ID, string Cont)
{
    AcID = ID;
    Content = Cont;
}
