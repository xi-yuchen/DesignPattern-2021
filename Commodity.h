#ifndef _COMMODITY_H_
#define _COMMODITY_H_

#include <string>
#include <list>
#include <iterator>

using std::string;
using std::list;

class Shop;

class CommodityInformation {
protected:
    string name, type; // 商品名
    int ID, price; // 价格
    Shop* shop; // 商品拥有者(店铺)

public:
    friend class CommodityInformaitonReader;
    friend class CommodityInformaitonSetter;

    CommodityInformation(int ID, string name, int price, Shop* shop);
    
    virtual bool Add(CommodityInformation* commodity);
    virtual bool Remove(CommodityInformation* commodity);

    virtual bool HasCommodity(CommodityInformation* commodity) = 0;
    virtual bool Enough(int amount) = 0;
    virtual bool Sell(int amount) = 0;
    virtual void Display() = 0;
};

class CommodityInformaitonReader{
private:
    CommodityInformation* source;
public:
    CommodityInformaitonReader() = default;
    void setCommodityInformation(CommodityInformation* info){
        source = info;
    }
    string getName() { return  source->name; }
    int getID() { return  source->ID; }
    string getType() { return  source->type; }
    int getPrice() { return source->price; }
    Shop* getShop() { return source->shop; }
};

class CommodityInformaitonSetter{
private:
    CommodityInformation* source;
public:
    CommodityInformaitonSetter() = default;
    void setCommodityInformation(CommodityInformation* info){
        source = info;
    }
    void setName(string name) { source->name = name; }
    void setID(int id) { source->ID = id; }
    void setType(string type) { source->type = type; }
    void setPrice(int price) { source->price = price; }
    bool addCommodity(CommodityInformation* commodity) { return source->Add(commodity); }
    bool removeCommodity(CommodityInformation* commodity) { return source->Remove(commodity); }
};

class SingleCommodity : public CommodityInformation {
protected:
    int amount; // 商品库存数量

public:
    SingleCommodity(int ID, string name, int price, Shop* shop, int amount);

    virtual bool HasCommodity(CommodityInformation* commodity);
    virtual bool Enough(int amount);
    virtual bool Sell(int amount);
    virtual void Display();
};

class CompositeCommodity : public CommodityInformation {
private:
    list<CommodityInformation*> commodity_list;
public:
    CompositeCommodity(int ID, string name, int price, Shop* shop);

    bool Add(CommodityInformation* commodity);
    bool Remove(CommodityInformation* commodity);

    virtual bool HasCommodity(CommodityInformation* commodity);
    virtual bool Enough(int amount);
    virtual bool Sell(int amount);
    virtual void Display();

    // 用于Iterator
    list<CommodityInformation*>* GetCommodityList() { return &commodity_list; };
    CompositeCommodityIterator& begin() { return CompositeCommodityIterator(commodity_list.begin()); }
    CompositeCommodityIterator& end() { return CompositeCommodityIterator(commodity_list.end()); }
    int size() { return commodity_list.size(); }
};

class CompositeCommodityIterator : public std::iterator<std::input_iterator_tag, CompositeCommodity> {
protected:
    list<CommodityInformation*>::iterator current;

public:
    CompositeCommodityIterator(list<CommodityInformation*>::iterator commodity);

    CompositeCommodityIterator& operator= (const CompositeCommodityIterator& iter);
    bool operator!= (const CompositeCommodityIterator& iter);
    bool operator== (const CompositeCommodityIterator& iter);
    CompositeCommodityIterator& operator++ ();
    CompositeCommodityIterator& operator++ (int);
    CommodityInformation& operator* () { return **current; }
};

#endif