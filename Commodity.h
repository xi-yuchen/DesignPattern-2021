#ifndef _COMMODITY_H_
#define _COMMODITY_H_

#include <string>
#include <list>

using std::string;
using std::list;

class Seller;

class Commodity {
protected:
    string name, type; // 商品名
    int ID, price; // 价格, 数量
    Seller* owner; // 商品拥有者(店铺)

public:
    Commodity(int ID, string name, int price, Seller* seller);

    int GetID() { return this->ID; }
    string GetName() { return this->name; }
    string GetType() { return this->type; }
    int GetPrice() { return this->price; }
    Seller* GetOwner() { return this->owner; }

    virtual bool Add(Commodity* commodity);
    virtual bool Remove(Commodity* commodity);

    virtual bool HasCommodity(Commodity* commodity) = 0;
    virtual bool Enough(int amount) = 0;
    virtual bool Sell(int amount) = 0;
    virtual void Display() = 0;
};

class SingleCommodity : public Commodity {
protected:
    int amount; // 商品库存数量

public:
    SingleCommodity(int ID, string name, int price, Seller* seller, int amount);

    virtual bool HasCommodity(Commodity* commodity);
    virtual bool Enough(int amount);
    virtual bool Sell(int amount);
    virtual void Display();
};

class CompositeCommodity : public Commodity {
protected:
    list<Commodity*> commodity_list;

public:
    CompositeCommodity(int ID, string name, int price, Seller* seller);

    bool Add(Commodity* commodity);
    bool Remove(Commodity* commodity);

    virtual bool HasCommodity(Commodity* commodity);
    virtual bool Enough(int amount);
    virtual bool Sell(int amount);
    virtual void Display();
};

#endif