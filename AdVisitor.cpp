#include "AdVisitor.h"
#include "AdvertisingSystem.h"


AdVisitor_Browse::AdVisitor_Browse()
{
}

AdVisitor_Browse::AdVisitor_Browse(int BrowseID)
{
    BrowseAdID = BrowseID;
}

void AdVisitor_Browse::Visit(AdvertisingSystem* AdSystem)
{
    if (BrowseAdID == -1)
    {        
        for (vector<AdNode*>::size_type ix = 0; ix != AdSystem->AdvertisingList.size(); ix++)
        {
            AdSystem->PrintAd(ix);
        }
        // 迭代器
    }
    else
    {
        int BrowseIndex = 0; // 寻找Index
        for (vector<AdNode*>::iterator iter = AdSystem->AdvertisingList.begin(); iter != AdSystem->AdvertisingList.end(); ++iter)
        {
            if ((*iter)->AdID == BrowseAdID)
                break;
            BrowseIndex++;
        }

        AdSystem->PrintAd(BrowseIndex);
    }
}

AdVisitor_Add::AdVisitor_Add(int ID, string Cont)
{
    AdID = ID;
    Content = Cont;
}

void AdVisitor_Add::Visit(AdvertisingSystem* AdSystem)
{
    if (AdID < 0)
    {
        cout << "ID < 0 !!!" << endl;
        return;
    }

    AdNode* ad = new AdNode(AdID, Content);

    AdSystem->AdvertisingList.push_back(ad);
}
