//
// Created by liruijie666 on 2021/10/31.
//
#include "CartInterface.h"

using namespace std;

void CartInterface::MainInterface(shopInterface shopInterface) {
    cart.setShopInterface(shopInterface);
    cart.add(10, 2);
    cart.display();
}

