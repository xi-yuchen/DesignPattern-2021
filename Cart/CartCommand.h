//
// Created by Frederick Mo on 2021/10/25.
//

#ifndef CART_CARTCOMMAND_H
#define CART_CARTCOMMAND_H

#include "Cart.h"

#include <list>
#include <sstream>
#include <iostream>

using std::cin;
using std::cout;
using std::list;
using std::map;

/**
 * Cart/购物车：主要包含Cart类/CartCommand类/CartInterface类
 * Cart类 => 声明购物车内部的基本逻辑/供外界调用的接口
 * CartCommand类 => 为用户调用声明的命令类，用户通过构造命令类的实例间接对购物车进行操作
 * CartInterface类 => 在本项目中所有用户对于购物车的相关操作集成的界面类
 */

/**
 * CartCommand类采用设计模式：Command / Observer
 *
 * Command设计模式逻辑：
 * 将对购物车(Cart)的操作封装到CartCommand类中，用户通过对CartCommand类进行操作达到对Cart类间接进行操作；
 * 将若干CartCommand类封装到ExecuteCommands宏命令类中，
 * 经由ExecuteCommands类的execute()方法将CartCommand类中的operation()方法一并执行
 *
 * Observer设计模式逻辑：
 * 在ExecuteCommands类中的execute()方法中体现：
 * 对于存储在宏命令中的CartCommand，当ExecuteCommands类调用execute()方法时，
 * 将通知(notify)其绑定的所有Observer(CartCommand)调用其内部setCart()方法绑定购物车Cart
 */



/// 对购物车操作的Command的基类
class CartCommand {
protected:
    Cart cart;
public:
    // 购物车命令的执行
    virtual void operation() = 0;
    // 链接Cart类 => 命令类需要对Cart进行操作
    void setCart(Cart cart);

    void setCustomer(Customer *customer);

    const Cart &getCart() const { return cart; }
    friend class ExecuteCommands;
};

/// 对CartCommand类进行存储的宏命令类，调用execute()类进行执行
class ExecuteCommands {
private:
    list<CartCommand*> commands;
    Cart cart;
public:

    void setCart(Cart cart);

    void addCommand(CartCommand *command);

    void removeCommand(CartCommand *command);
    // 宏命令的执行操作方法，将执行其中所有命令的operate()方法
    void execute();

    const Cart &getCart() const { return cart; }
};

/// 增加商品的Command类
class AddCommodity : public CartCommand {
private:
    int id, amount;
public:
    AddCommodity(int id, int amount) : id(id), amount(amount) {}

    void operation() override;
};

/// 移除某一ID的商品的Command类
class RemoveCommodity : public CartCommand {
private:
    int id;
public:
    explicit RemoveCommodity(int id) : id(id) {}

    void operation() override;
};

/// 按数量移除某一ID的商品的Command类
class RemoveSomeCommodity : public CartCommand {
private:
    int id, amount;
public:
    RemoveSomeCommodity(int id, int amount) : id(id), amount(amount) {}

    void operation() override;
};

/// 展示购物车所有商品信息的Command类
class DisplayCart : public CartCommand {
public:
    void operation() override;
};

/// 结算购物车内所有商品的Command类
class PayAll : public CartCommand {
public:
    void operation() override;
};

/// 结算购物车内某一ID的所有商品的Command类
class PaySingleCommodity : public CartCommand {
private:
    int id;
public:
    explicit PaySingleCommodity(int id) : id(id) {}

    void operation() override;
};

/// 按数量结算购物车内某一ID的商品的Command类
class PaySomeCommodity : public CartCommand {
private:
    int id, amount;
public:
    PaySomeCommodity(int id, int amount) : id(id), amount(amount) {}

    void operation() override;
};

/// 展示购物车内所有商品/购物车内某一ID的所有商品/某一数量的某一ID的商品的最优惠价格的Command类
class CalculateOptionalPrice : public CartCommand {
private:
    map<CommodityInformation *, int> commodities;
public:
    // 构造函数1 => 计算购物车内所有商品
    CalculateOptionalPrice();
    // 构造函数2 => 计算购物车内某ID的所有商品
    explicit CalculateOptionalPrice(int id);
    // 构造函数3 => 计算某一数量的某ID的所有商品
    CalculateOptionalPrice(int id, int amount);

    void operation() override;

    const map<CommodityInformation *, int> &getCommodities() const { return commodities; }

    void setCommodities(const map<CommodityInformation *, int> &_commodities) { commodities = _commodities; }
};

#endif //CART_CARTCOMMAND_H
