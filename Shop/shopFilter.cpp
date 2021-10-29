
#include "shopFilter.h"
/*
 * The concrete code of introduction in shopFilter.h
 * Three classes and three functions according to the remark score of the shop.
 */
list<Shop *> HighShopFilter::selectShop(list<Shop *> ShopList) {
    list<Shop *> HighShopList;
    for (auto shop:ShopList) {
        if (shop->getTotalRemarkScore() >= 7.50)
            HighShopList.push_back(shop);
    }
    return HighShopList;
}

list<Shop *> MidShopFilter::selectShop(list<Shop *> ShopList) {
    list<Shop *> MidShopList;
    for (auto shop:ShopList) {
        if (shop->getTotalRemarkScore() >= 5.00 && shop->getTotalRemarkScore() < 7.50)
            MidShopList.push_back(shop);
    }
    return MidShopList;
}

list<Shop *> LowShopFilter::selectShop(list<Shop *> ShopList) {
    list<Shop *> LowShopList;
    for (auto shop:ShopList) {
        if (shop->getTotalRemarkScore() >= 2.50 && shop->getTotalRemarkScore() < 5.00)
            LowShopList.push_back(shop);
    }
    return LowShopList;
}