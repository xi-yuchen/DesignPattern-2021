#ifndef _COMMODITY_H_
#define _COMMODITY_H_

#include <string>
#include <list>
#include <iterator>

using std::string;
using std::list;

class Shop;

template<class return_T, class parameter_T> // 设计模式: Command
class Command {
public:
    virtual return_T execute(parameter_T) = 0;
};

class CommodityInformation {
protected:
    string name, type; // 商品名
    int ID; // ID
    float price; // 价格
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
    friend class CommodityInformationVipReader;
    friend class CommodityInformationSetter;
    friend class CommoditySale;
    friend class CommodityDisplay;

    CommodityInformation(int ID, string name, float price, int shopID);
};

class CommodityInformationReader {
protected:
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
    virtual float getPrice() { return source->price; }
    Shop* getShop() { return source->shop; }
    int getShopID(){return source->shopID;}
};

class CommodityInformationVipReader : CommodityInformationReader {
public:
    float getPrice() override { return source->price * 0.8; } // vip用户打八折
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
    void setPrice(float price) { source->price = price; }
    bool addCommodity(CommodityInformation* commodity) { return source->Add(commodity); }
    bool removeCommodity(CommodityInformation* commodity) { return source->Remove(commodity); }
};

class CommoditySale { // 设计模式: command
private:
    CommodityInformation* source;
public:
    CommoditySale() = default;
    CommoditySale(CommodityInformation* info) : source(info) { }
    void setCommodityInformation(CommodityInformation* info){
        source = info;
    }
    bool ifEnough(int amount) { return source->Enough(amount); }
    virtual bool execute(int amount) { return source->Sell(amount); }
};

class CommodityDisplay { // 设计模式: command
private:
    CommodityInformation* source;
public:
    CommodityDisplay() = default;
    CommodityDisplay(CommodityInformation* info) : source(info) { }
    void setCommodityInformation(CommodityInformation* info){
        source = info;
    }
    virtual void execute() { source->Display(); }
};

class SingleCommodity : public CommodityInformation { // 设计模式: composite, 桥接模式
protected:
    int amount; // 商品库存数量

    virtual bool HasCommodity(CommodityInformation* commodity);

public:
    SingleCommodity(int ID, string name, float price,int shopID, int amount);

    virtual bool Enough(int amount);
    virtual bool Sell(int amount);
    virtual void Display();
};

class CompositeCommodity;  // 设计模式: iterator
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

class CompositeCommodity : public CommodityInformation { // 设计模式: composite
protected:
    list<CommodityInformation*> commodity_list;

    virtual bool HasCommodity(CommodityInformation* commodity);

public:
    CompositeCommodity(int ID, string name, float price, int shopID);

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