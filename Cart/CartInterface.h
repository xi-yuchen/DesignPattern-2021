//
// Created by liruijie666 on 2021/10/31.
//

#ifndef DESIGNPATTERN_2021_CARTINTERFACE_H
#define DESIGNPATTERN_2021_CARTINTERFACE_H

#include "CartCommand.h"
#include "Cart.h"
#include "../Order/OrderInterface.h"

using namespace std;

/**
 * Cart/购物车：主要包含Cart类/CartCommand类/CartInterface类
 * Cart类 => 声明购物车内部的基本逻辑/供外界调用的接口
 * CartCommand类 => 为用户调用声明的命令类，用户通过构造命令类的实例间接对购物车进行操作
 * CartInterface类 => 在本项目中所有用户对于购物车的相关操作集成的界面类
 */

class CartInterface {
private:
    Cart cart;
public:
    // 用户直接进行操作的主成员方法
    void MainInterface(shopInterface shopInterface, Customer* customer,OrderInterface &orderInterface);
    // 获取当前关联购物车信息
    const Cart &getCart() const {return cart;}
    // 关联购物车
    void setCart(const Cart &_cart) {cart = _cart;}
};

#endif //DESIGNPATTERN_2021_CARTINTERFACE_H
