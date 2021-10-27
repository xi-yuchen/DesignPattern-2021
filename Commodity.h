#ifndef _COMMODITY_H_
#define _COMMODITY_H_

#include <string>
#include <list>
#include <iterator>

using std::string;
using std::list;

class Shop;

class Commodity {
protected:
    string name, type; // 商品名
    int ID, price; // 价格, 数量
    Shop* shop; // 商品拥有者(店铺)
    list<Commodity*> commodity_list; // 用于Iterator

public:
    Commodity(int ID, string name, int price, Shop* shop);

    string GetName() { return this->name; }
    string GetType() { return this->type; }
    int GetPrice() { return this->price; }
    Shop* GetShop() { return this->shop; }
    
    virtual bool Add(Commodity* commodity);
    virtual bool Remove(Commodity* commodity);

    virtual bool HasCommodity(Commodity* commodity) = 0;
    virtual bool Enough(int amount) = 0;
    virtual bool Sell(int amount) = 0;
    virtual void Display() = 0;

    // 用于Iterator
    list<Commodity*>* GetCommodityList() { return &commodity_list; };
    CommodityIterator& begin() { return CommodityIterator(commodity_list.begin()); }
    CommodityIterator& end() { return CommodityIterator(commodity_list.end()); }
    int size() { return commodity_list.size(); }
};

class SingleCommodity : public Commodity {
protected:
    int amount; // 商品库存数量

public:
    SingleCommodity(int ID, string name, int price, Shop* shop, int amount);

    list<Commodity*>* GetCommodityList() { return &commodity_list; } ; // 用于Iterator

    virtual bool HasCommodity(Commodity* commodity);
    virtual bool Enough(int amount);
    virtual bool Sell(int amount);
    virtual void Display();
};

class CompositeCommodity : public Commodity {
public:
    CompositeCommodity(int ID, string name, int price, Shop* shop);

    bool Add(Commodity* commodity);
    bool Remove(Commodity* commodity);

    virtual bool HasCommodity(Commodity* commodity);
    virtual bool Enough(int amount);
    virtual bool Sell(int amount);
    virtual void Display();
};

class CommodityIterator : public std::iterator<std::input_iterator_tag, Commodity> {
protected:
    list<Commodity*>::iterator current;

public:
    CommodityIterator(list<Commodity*>::iterator commodity);

    CommodityIterator& operator= (const CommodityIterator& iter);
    bool operator!= (const CommodityIterator& iter);
    bool operator== (const CommodityIterator& iter);
    CommodityIterator& operator++ ();
    CommodityIterator& operator++ (int);
    Commodity& operator* () { return **current; }
};

#endif