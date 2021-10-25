//
// Created by Frederick Mo on 2021/10/25.
//

#ifndef CART_CARTCOMMAND_H
#define CART_CARTCOMMAND_H

#include "SelectedCommodity.h"
#include "Cart.h"

#include <list>
#include <sstream>
#include <iostream>

using std::cin;
using std::cout;
using std::list;

class CartCommand {
//protected:
//    Cart* cart;
public:
//    CartCommand(Cart *cart) : cart(cart) {}
    virtual void operation() = 0;
};

class ExecuteCommands {
private:
    list<CartCommand*> commands;
public:
    void addCommand(CartCommand *command);
    void removeCommand(CartCommand *command);
    void execute();
};

class AddCommodity : public CartCommand {
private:
    SelectedCommodity* commodity;
    Cart* cart;
public:
    AddCommodity(SelectedCommodity *commodity, Cart *cart) : commodity(commodity), cart(cart) {}
    void operation();
};

class RemoveCommodity : public CartCommand {
private:
    int id;
    Cart* cart;
public:
    RemoveCommodity(int id, Cart *cart) : id(id), cart(cart) {}
    void operation();
};

class RemoveSomeCommodity : public CartCommand {
private:
    int id, amount;
    Cart* cart;
public:
    RemoveSomeCommodity(int id, int amount, Cart *cart) : id(id), amount(amount), cart(cart) {}
    void operation();
};

class DisplayCart : public CartCommand {
private:
    Cart* cart;
public:
    explicit DisplayCart(Cart *cart) : cart(cart) {}
    void operation();
};

class PayAll : public CartCommand {
private:
    Cart* cart;
public:
    explicit PayAll(Cart *cart) : cart(cart) {}
    void operation();
};

class PaySingleCommodity : public CartCommand {
private:
    int id;
    Cart* cart;
public:
    PaySingleCommodity(int id, Cart *cart) : id(id), cart(cart) {}
    void operation();
};

class PaySomeCommodity : public CartCommand {
private:
    int id, amount;
    Cart* cart;
public:
    PaySomeCommodity(int id, int amount, Cart *cart) : id(id), amount(amount), cart(cart) {}
    void operation();
};

#endif //CART_CARTCOMMAND_H
