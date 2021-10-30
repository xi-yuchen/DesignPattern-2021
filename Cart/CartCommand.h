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

/**
 * 2021.10.26 12:40修改：
 * 修改了Command的逻辑，如果每个Command子类的构造都需要Cart的参数的话必定会造成冗余，
 * 所以在基类CartCommand里添加了一个protected的Cart，然后在宏命令ExecuteCommands里给宏命令当中包含的Command依次指定Cart。
 */

class CartCommand {
protected:
    Cart* cart;
public:
//    CartCommand(Cart *cart) : cart(cart) {}
    virtual void operation() = 0;
    void setCart(Cart *cart);
};

class ExecuteCommands {
private:
    list<CartCommand*> commands;
    Cart *cart;
public:
    void setCart(Cart *cart);
    void addCommand(CartCommand *command);
    void removeCommand(CartCommand *command);
    void execute();
};

class AddCommodity : public CartCommand {
private:
//    SelectedCommodity* commodity;
//    Cart* cart;
    int id, amount;
public:
    AddCommodity(int id, int amount) : id(id), amount(amount) {}
    void operation();
};

class RemoveCommodity : public CartCommand {
private:
    int id;
//    Cart* cart;
public:
    RemoveCommodity(int id) : id(id) {}
    void operation();
};

class RemoveSomeCommodity : public CartCommand {
private:
    int id, amount;
//    Cart* cart;
public:
    RemoveSomeCommodity(int id, int amount) : id(id), amount(amount) {}
    void operation();
};

class DisplayCart : public CartCommand {
//private:
//    Cart* cart;
public:
//    explicit DisplayCart() {}
    void operation();
};

class PayAll : public CartCommand {
//private:
//    Cart* cart;
public:
//    explicit PayAll() {}
    void operation();
};

class PaySingleCommodity : public CartCommand {
private:
    int id;
//    Cart* cart;
public:
    PaySingleCommodity(int id) : id(id) {}
    void operation();
};

class PaySomeCommodity : public CartCommand {
private:
    int id, amount;
//    Cart* cart;
public:
    PaySomeCommodity(int id, int amount) : id(id), amount(amount) {}
    void operation();
};

#endif //CART_CARTCOMMAND_H
