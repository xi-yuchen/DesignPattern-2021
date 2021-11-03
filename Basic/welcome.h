//
// Created by liruijie666 on 2021/10/30.
//

#ifndef DESIGNPATTERN_2021_WELCOME_H
#define DESIGNPATTERN_2021_WELCOME_H

#include <iostream>
#include "../Shop/shopInterface.h"
#include "../Customer/Customer.h"

using namespace std;
/*
 * 这个类集成了程序与用户交互时给用户输出的信息
 * showCmds为基类，其中有一个函数showUserCmds()
 *      该函数在具体派生类中会根据具体情况向用户输出不同的交互信息。
 *      目前有用户命令、店铺命令、商品命令、购物车命令、订单命令等。
 */
class showCmds {
public:
    virtual void showUserCmds() = 0;
};

class showUserShopCmds : public showCmds {
public:
    void showUserCmds();
};

class showUserInfoCmds : public showCmds {
public:
    void showUserCmds();
};

class showUserInterfaceCmds : public showCmds {
public:
    void showUserCmds();
};

class showUserCartCmds : public showCmds {
public:
    void showUserCmds();
};

class showUserOrderCmds : public showCmds {
public:
    void showUserCmds();
};

class ConcreteCommands {
private:
    vector<string> _concreteCommands;
public:
    const vector<string> &getConcreteCommands() const {return _concreteCommands;}

    void setConcreteCommands(const vector<string> &concreteCommands) {_concreteCommands = concreteCommands;}
};
/*
 * 设计模式 - 适配器模式 Adapter Mode
 * 使用适配器模式可以在派生类中融入外部的其他对象和增加基类中没有的功能
 * 本适配器中，融入了外部一个包含所有命令集合的类，以及输出它们的新函数（基类没有）
 * 增强了类和对象的功能性。
 */
class showUserCmdsAdapter : public showCmds {
private:
    ConcreteCommands concreteCommands;
public:
    void displayExistingCommands();
};

void Initial();

#endif //DESIGNPATTERN_2021_WELCOME_H
