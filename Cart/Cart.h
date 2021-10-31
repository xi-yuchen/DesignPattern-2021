//
// Created by Frederick Mo on 2021/10/21.
//

#ifndef SOFTWARE_DESIGN_PATTERNS_TASK_CART_H
#define SOFTWARE_DESIGN_PATTERNS_TASK_CART_H


#include "Commodity.h"
#include "Facade.h"
#include "Order.h"

#include "Customer.h"
#include "shopInterface.h"

#include <list>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <map>
#include <iostream>
using namespace std;


/**
 * 写点接口在这
 */

//class CommodityInformation {
//protected:
//    string name, type; // 商品名
//    int ID, price; // 价格
//
//public:
//    friend class CommodityInformationReader;
//
//    CommodityInformation(int ID, string name, int price)
//};
//
//class CommodityInformationReader {
//private:
//    CommodityInformation* source;
//public:
//    CommodityInformationReader() = default;
//    CommodityInformationReader(CommodityInformation* info) : source(info) { }
//    void setCommodityInformation(CommodityInformation* info){
//        source = info;
//    }
//    string getName() { return  source->name; }
//    int getID() { return  source->ID; }
//    string getType() { return  source->type; }
//    int getPrice() { return source->price; }
//};
//
//
//class CustomerInformation {
//private:
//    int _id;
//    string _name;
//    string _phone;
//    string _email;
//    int _points;
//    friend class VirtualCustomerInformationReader;
//public:
//    void setID(int id) { _id = id; }
//    CustomerInformation* clone(){
//        auto* result=new CustomerInformation(*this);
//        return result;
//    }
//};
//
//class VirtualCustomerInformationReader;
//
//class Customer {
//protected:
//    CustomerInformation* _info;
//    VirtualCustomerInformationReader *_customer_reader{};
//    CommodityInformationReader *_commodity_reader{};
//public:
//    explicit Customer(){
//        _info=new CustomerInformation;
//    }
//    VirtualCustomerInformationReader *getCustomerReader(){
//        return this->_customer_reader;
//    }
//
//    CommodityInformationReader* getCommodityReader(){
//        return this->_commodity_reader;
//    }
//
//    void setCustomerInformationReader(VirtualCustomerInformationReader* customer_reader){
//        _customer_reader=customer_reader;
//    }
//
//    void setCommodityInformationReader(CommodityInformationReader* commodity_reader){
//        _commodity_reader=commodity_reader;
//    }
//};
//
//class VirtualCustomerInformationReader{
//private:
//    CustomerInformation* _source;
//public:
//    explicit VirtualCustomerInformationReader(CustomerInformation* source):_source(source){}
//    virtual int getID();
//    virtual string getName();
//    virtual string getPhone();
//    virtual string getEmail();
//    virtual int getPoints();
//    virtual int getLevel();
//};
//
//
//
//class CustomerSet{
//private:
//    vector<Customer*> _customers;
//    int _index;
//    static CustomerSet* _instance;
//    CustomerSet(){}
//public:
//    static CustomerSet* getInstance(){
//        if(_instance==nullptr)
//            _instance=new CustomerSet;
//        return _instance;
//    }
//    void addCustomer(Customer* customer);
//    void deleteCustomer(Customer* customer);
//    bool switchCustomer(int index);
//    Customer* getCustomer();
//    vector<Customer*> getCustomers();
//};
//
//class Facade {
//public:
//    float CalOptionalDecision(map<CommodityInformation*, int> commodities) {
//        return 100.0;
//    }
//};
//
//
//class Order {
//private:
//    int customerID;
//    map<CommodityInformation*, int> commodities;
//    float totalPrice;
//public:
//    Order(int customerID, map<CommodityInformation*, int> commodities, int totalPrice) : customerID(customerID), commodities(commodities), totalPrice(totalPrice) {}
//};
//
//class OrderList {
//private:
//    list<Order*> orderList;
//public:
//    void addOrder(Order *order) { orderList.push_back(order); }
//};
//
//class shopInterface {
//private:
//    map<CommodityInformation *, int> _commodityList;
//public:
//    const map<CommodityInformation *, int> &getCommodityList() const { return _commodityList; }
//    CommodityInformation *addCart(int ID) {
//        CommodityInformationReader reader;
//        for(auto _commodity:_commodityList){
//            reader.setCommodityInformation(_commodity.first);
//            if(reader.getID()==ID)
//                return _commodity.first;
//        }
//        return nullptr;
//    }
//
//};




class Cart {
private:
    map<CommodityInformation*, int> commodityList;

    OrderList *orderList;
    Facade *activities;

    Customer *customer;
    CommodityInformationReader *infoReader;
    shopInterface *interface;
public:
//    Cart() {
//        customer = CustomerSet::getInstance()->getCustomer();
//        infoReader = customer->getCommodityReader();
//    }

    Cart() = default;

//    void setCustomer(Customer *customer) { this->customer = customer; }

    void connectOrderList(OrderList *orderList);
    void connectActivities(Facade *activities);
//    void setShopInterface(shopInterface *interface) {
//        this->interface = interface;
//    }
    void setShopInterface(shopInterface *interface);
    void setCustomer();

    float calculateOptionalPrice(map<CommodityInformation*, int> commodities);

    void add(int id, int amount);
    void remove(int id);
    void remove(int id, int amount);
    void display();

    map<CommodityInformation*, int> getCommodity();
    map<CommodityInformation*, int> getCommodity(int id);
    map<CommodityInformation*, int> getCommodity(int id, int amount);

    void pay();
    void pay(int id);
    void pay(int id, int amount);

    static void displayCommodityInfo(CommodityInformation *commodityInfo);

    //map<CommodityInformationReader*, int> getAllCommodity() { return commodityList; }
};

#endif //SOFTWARE_DESIGN_PATTERNS_TASK_CART_H
