#include "ActivitySystem.h"
#include "Commodity.h"
#include "AcVisitor.h"

ActivitySystem* ActivitySystem::AcSystemInstance = nullptr;


AcNode_Discount::AcNode_Discount(int ID, string Cont, vector<int>& CommodityInformaitonReaderIDList, float DisRate) : AcNode(ID, Cont)
{
    SatisfyCommodityInformaitonReaderIDList = CommodityInformaitonReaderIDList;
    DiscountRate = DisRate;
}

float AcNode_Discount::ExecuteActivity(CommodityInformaitonReader* BuyCommodityInformaitonReader, int Amount)
{
    if (IsSatisfy(BuyCommodityInformaitonReader))
        return CalPrice(BuyCommodityInformaitonReader, Amount);
    else
        return BuyCommodityInformaitonReader->getPrice() * Amount * 1.0f;
}

bool AcNode_Discount::IsSatisfy(CommodityInformaitonReader* BuyCommodityInformaitonReader)
{
    for (vector<int>::iterator iter = SatisfyCommodityInformaitonReaderIDList.begin(); iter != SatisfyCommodityInformaitonReaderIDList.end(); ++iter)
    {
        if (BuyCommodityInformaitonReader->getID() == *iter)
            return true;
    }
    return false;
}

float AcNode_Discount::CalPrice(CommodityInformaitonReader* BuyCommodityInformaitonReader, int Amount)
{
    return DiscountRate * BuyCommodityInformaitonReader->getPrice() * Amount;
}

AcNode_FullReduction::AcNode_FullReduction(int ID, string Cont, float Thd, float RedAmount) : AcNode(ID, Cont)
{
    Threshold = Thd;
    ReductionAmount = RedAmount;
}

float AcNode_FullReduction::ExecuteActivity(map<CommodityInformaitonReader*, int>& BuyCommodityInformaitonReader)
{
    if (IsSatisfy(BuyCommodityInformaitonReader))
        return CalPrice(BuyCommodityInformaitonReader);
    return CalPrice(BuyCommodityInformaitonReader) + ReductionAmount;
}

bool AcNode_FullReduction::IsSatisfy(map<CommodityInformaitonReader*, int>& BuyCommodityInformaitonReader)
{
    float sumPrize = 0;
    for (auto iter = BuyCommodityInformaitonReader.begin(); iter != BuyCommodityInformaitonReader.end(); ++iter)
    {
        sumPrize += (*iter).first->getPrice() * (*iter).second;
    }
    if (sumPrize >= Threshold)
        return true;
    return false;
}

float AcNode_FullReduction::CalPrice(map<CommodityInformaitonReader*, int>& BuyCommodityInformaitonReader)
{
    float sumPrize = 0;
    for (auto iter = BuyCommodityInformaitonReader.begin(); iter != BuyCommodityInformaitonReader.end(); ++iter)
    {
        sumPrize += (*iter).first->getPrice() * (*iter).second;
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
