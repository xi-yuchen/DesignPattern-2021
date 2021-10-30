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
    int shopID;

    virtual bool Add(CommodityInformation* commodity);
    virtual bool Remove(CommodityInformation* commodity);
    virtual bool HasCommodity(CommodityInformation* commodity) = 0;
    virtual bool Enough(int amount) = 0;
    virtual bool Sell(int amount) = 0;
    virtual void Display() = 0;
    friend class CompositeCommodity;

public:
    friend class CommodityInformationReader;
    friend class CommodityInformationSetter;
    friend class CommoditySale;
    friend class CommodityDisplay;

    CommodityInformation(int ID, string name, int price, int shopID);
};

class CommodityInformationReader {
private:
    CommodityInformation* source;
public:
    CommodityInformationReader() = default;
    CommodityInformationReader(CommodityInformation* info) : source(info) { }
    void setCommodityInformation(CommodityInformation* info){
        source = info;
    }
    string getName() { return  source->name; }
    int getID() { return  source->ID; }
    string getType() { return  source->type; }
    int getPrice() { return source->price; }
    Shop* getShop() { return source->shop; }
    int getShopID(){return source->shopID;}
};

class CommodityInformationSetter {
private:
    CommodityInformation* source;
public:
    CommodityInformationSetter() = default;
    CommodityInformationSetter(CommodityInformation* info) : source(info) { }
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

class CommoditySale {
private:
    CommodityInformation* source;
public:
    CommoditySale() = default;
    CommoditySale(CommodityInformation* info) : source(info) { }
    void setCommodityInformation(CommodityInformation* info){
        source = info;
    }
    bool ifEnough(int amount) { return source->Enough(amount); }
    bool execute(int amount) { return source->Sell(amount); }
};

class CommodityDisplay {
private:
    CommodityInformation* source;
public:
    CommodityDisplay() = default;
    CommodityDisplay(CommodityInformation* info) : source(info) { }
    void setCommodityInformation(CommodityInformation* info){
        source = info;
    }
    void execute() { source->Display(); }
};

class SingleCommodity : public CommodityInformation {
protected:
    int amount; // 商品库存数量

    virtual bool HasCommodity(CommodityInformation* commodity);

public:
    SingleCommodity(int ID, string name, int price,int shopID, int amount);

    virtual bool Enough(int amount);
    virtual bool Sell(int amount);
    virtual void Display();
};

class CompositeCommodity;
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

class CompositeCommodity : public CommodityInformation {
protected:
    list<CommodityInformation*> commodity_list;

    virtual bool HasCommodity(CommodityInformation* commodity);

public:
    CompositeCommodity(int ID, string name, int price, int shopID);

    bool Add(CommodityInformation* commodity);
    bool Remove(CommodityInformation* commodity);

    virtual bool Enough(int amount);
    virtual bool Sell(int amount);
    virtual void Display();

    // 用于Iterator
    list<CommodityInformation*>* GetCommodityList() { return &commodity_list; };
    CompositeCommodityIterator& begin() {
        CompositeCommodityIterator* iter = new CompositeCommodityIterator(commodity_list.begin());
        return *iter;
    }
    CompositeCommodityIterator& end() {
        CompositeCommodityIterator* iter = new CompositeCommodityIterator(commodity_list.end());
        return *iter;
    }
    int size() { return commodity_list.size(); }
};

#endif