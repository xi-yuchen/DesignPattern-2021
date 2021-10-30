#include "ActivitySystem.h"
#include "Commodity.h"
#include "AcVisitor.h"
#include "../Customer/Customer.h"
#include "../Customer/Customers.h"
ActivitySystem* ActivitySystem::AcSystemInstance = nullptr;


AcNode_Discount::AcNode_Discount(int ID, string Cont, vector<int>& CommodityInformationReaderIDList, float DisRate) : AcNode(ID, Cont)
{
    SatisfyCommodityInformationIDList = CommodityInformationIDList;
    DiscountRate = DisRate;
}

float AcNode_Discount::ExecuteActivity(CommodityInformation* BuyCommodityInformation, int Amount)
{
    auto* customers=CustomerSet::getInstance();
    auto* customer=customers->getCustomer();
    auto* reader=customer->getCommodityReader();
    reader->setCommodityInformation(BuyCommodityInformation);
    if (IsSatisfy(BuyCommodityInformation))
        return CalPrice(BuyCommodityInformation, Amount);
    else
        return reader->getPrice() * Amount * 1.0f;
}

bool AcNode_Discount::IsSatisfy(CommodityInformation* BuyCommodityInformation)
{
    for (vector<int>::iterator iter = SatisfyCommodityInformationIDList.begin(); iter != SatisfyCommodityInformationIDList.end(); ++iter)
    {
        if (BuyCommodityInformation->getID() == *iter)
            return true;
    }
    return false;
}

float AcNode_Discount::CalPrice(CommodityInformation* BuyCommodityInformation, int Amount)
{
    auto* reader=CustomerSet::getInstance()->getCustomer()->getCommodityReader();
    reader->setCommodityInformation(BuyCommodityInformation);
    return DiscountRate * reader->getPrice() * Amount;
}

AcNode_FullReduction::AcNode_FullReduction(int ID, string Cont, float Thd, float RedAmount) : AcNode(ID, Cont)
{
    Threshold = Thd;
    ReductionAmount = RedAmount;
}

float AcNode_FullReduction::ExecuteActivity(map<CommodityInformation*, int>& BuyCommodityInformation)
{
    if (IsSatisfy(BuyCommodityInformation))
        return CalPrice(BuyCommodityInformation);
    return CalPrice(BuyCommodityInformation) + ReductionAmount;
}

bool AcNode_FullReduction::IsSatisfy(map<CommodityInformation*, int>& BuyCommodityInformation)
{
    auto* reader=CustomerSet::getInstance()->getCustomer()->getCommodityReader();

    float sumPrize = 0;
    for (auto iter = BuyCommodityInformation.begin(); iter != BuyCommodityInformation.end(); ++iter)
    {
        reader->setCommodityInformation(iter->first);
        sumPrize += reader->getPrice() * (*iter).second;
    }
    if (sumPrize >= Threshold)
        return true;
    return false;
}

float AcNode_FullReduction::CalPrice(map<CommodityInformation*, int>& BuyCommodityInformation)
{
    auto* Customers=CustomerSet::getInstance();
    auto* Customer=Customers->getCustomer();
    auto* Reader=Customer->getCommodityReader();
    float sumPrize = 0;
    for (auto iter = BuyCommodityInformation.begin(); iter != BuyCommodityInformation.end(); ++iter)
    {
        Reader->setCommodityInformation(iter->first);
        sumPrize += Reader->getPrice() * (*iter).second;
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

