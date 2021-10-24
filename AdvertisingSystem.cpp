#include "AdvertisingSystem.h"
#include "AdVisitor.h"
#include <iostream>
#include <string>
using namespace std;

AdvertisingSystem* AdvertisingSystem::AdSystemInstance = nullptr;

AdvertisingSystem::~AdvertisingSystem()
{
    for (auto AdElem : AdvertisingList)
    {
        delete AdElem;
    }
    
    if (AdSystemInstance != nullptr)
        delete AdSystemInstance;

}

AdvertisingSystem* AdvertisingSystem::GetAdSystemInstance()
{
    if (AdSystemInstance == nullptr)
        AdSystemInstance = new AdvertisingSystem();

    return AdSystemInstance;
}

void AdvertisingSystem::Accept(AdVisitor* Visitor)
{
    Visitor->Visit(this);
}

void AdvertisingSystem::PrintAd(int Index)
{
    int len = AdvertisingList.size();

    if (Index > len - 1)
        return;
    
    cout << "Advertising ID : " << AdvertisingList[Index]->AdID << endl;
    cout << "Advertising Content : " << AdvertisingList[Index]->Content << endl;
}

AdvertisingSystem::AdvertisingSystem()
{
}
