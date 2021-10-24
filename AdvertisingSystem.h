#pragma once

#include <string>
#include <vector>
using namespace std;

//使用设计模式：单例

class AdVisitor;

struct AdNode//广告
{
    int AdID;
    string Content;

    AdNode(int ID, string Cont)
    {
        AdID = ID;
        Content = Cont;
    }
};

class AdvertisingSystem//广告子系统（单例）
{
public:
    friend class AdVisitor_Browse;
    friend class AdVisitor_Add;

    ~AdvertisingSystem();

    static AdvertisingSystem* GetAdSystemInstance();

    void Accept(AdVisitor* Visitor);

    void PrintAd(int Index);//打印广告

private:

    AdvertisingSystem();

    static AdvertisingSystem* AdSystemInstance;

    vector<AdNode*> AdvertisingList;
};
