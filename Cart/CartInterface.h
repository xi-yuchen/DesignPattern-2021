//
// Created by liruijie666 on 2021/10/31.
//

#ifndef DESIGNPATTERN_2021_CARTINTERFACE_H
#define DESIGNPATTERN_2021_CARTINTERFACE_H

#include "CartCommand.h"
#include "Cart.h"
#include "../Order/OrderInterface.h"

using namespace std;

class CartInterface {
private:
    Cart cart;
public:
    void MainInterface(shopInterface shopInterface, Customer* customer,OrderInterface &orderInterface);
    const Cart &getCart() const {return cart;}
    void setCart(const Cart &_cart) {cart = _cart;}
};

#endif //DESIGNPATTERN_2021_CARTINTERFACE_H
