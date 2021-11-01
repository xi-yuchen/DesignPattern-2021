//
// Created by liruijie666 on 2021/10/31.
//

#ifndef DESIGNPATTERN_2021_CARTINTERFACE_H
#define DESIGNPATTERN_2021_CARTINTERFACE_H

#include "CartCommand.h"
#include "Cart.h"

using namespace std;

class CartInterface {
private:
    Cart cart;
public:
    void MainInterface(shopInterface shopInterface, Customer* customer);
    const Cart &getCart() const {return cart;}
};

#endif //DESIGNPATTERN_2021_CARTINTERFACE_H
