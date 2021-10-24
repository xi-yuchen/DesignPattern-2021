#pragma once
#include <string>
#include <vector>
using namespace std;

//使用设计模式：单例

class AcVisitor;

class Commodity;

class AcNode//活动父类
{
public:

    AcNode(int ID, string Cont);//两类活动id不可相同
    
    int AcID;
    string Content;
};

class AcNode_Discount : public AcNode//打折类活动子类
{
public:

    AcNode_Discount(int ID, string Cont, vector<int>& CommodityIDList, float DisRate);
    
    float ExecuteActivity(Commodity* BuyCommodity); // 若商品打折，则返回商品打完折的价格，否则返回原价

    bool IsSatisfy(Commodity* BuyCommodity);//判断商品是否打折

private:

    float CalPrice(Commodity* BuyCommodity);//返回商品打完折后的价格

    vector<int> SatisfyCommodityIDList;

    float DiscountRate;
};

class AcNode_FullReduction : public AcNode//满减类活动子类
{
public:

    AcNode_FullReduction(int ID, string Cont, float Thd, float RedAmount);

    float ExecuteActivity(vector<Commodity*>& BuyCommodity); //若商品达到满减金额，则返回商品满减后的价格，否则返回原价

private:

    bool IsSatisfy(vector<Commodity*>& BuyCommodity);//判断商品是否满减

    float CalPrice(vector<Commodity*>& BuyCommodity);//返回商品满减后的价格

    float Threshold;
    float ReductionAmount;
};

class ActivitySystem//活动子系统
{
public:
    friend class AcVisitor_Browse;
    friend class AcVisitor_Add;
    friend class AcVisitor_Recommend;
    friend class AcVisitor_CP_Discount;
    friend class AcVisitor_CP_FullRedu;

    ~ActivitySystem();

    static ActivitySystem* GetAcSystemInstance();

    void Accept(AcVisitor* Visitor);

    void PrintAc_D(int Index);//打印打折类活动
    void PrintAc_F(int Index);//打印满减类活动

private:

    ActivitySystem();

    static ActivitySystem* AcSystemInstance;

    vector<AcNode_Discount*> DiscountActivityList;
    vector<AcNode_FullReduction*> FullReductionActivityList;
};
