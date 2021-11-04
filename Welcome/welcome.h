//
// Created by liruijie666 on 2021/10/30.
//

#ifndef DESIGNPATTERN_2021_WELCOME_H
#define DESIGNPATTERN_2021_WELCOME_H

#include <iostream>
#include "../Shop/shopInterface.h"
#include "../Customer/Customer.h"

using namespace std;
/* 设计模式 模块模式 Module Pattern
 * 模块模式一般用于集成、打包全局要使用的相关的类、方法、函数
 * 这个类集成了全局中主程序与用户交互时给用户输出的信息。
 * showCmds为基类，其中有一个函数showUserCmds()以及适配器等
 *      该函数在具体派生类中会根据具体情况向用户输出不同的交互信息。
 *      目前有用户命令、店铺命令、商品命令、购物车命令、订单命令等。
 * 上述函数只负责输出命令提示，用户可以根据上述提示在主函数进行多种操作
 */

//用户命令基类
class showCmds {
public:
    virtual void showUserCmds() = 0;
};

//为用户展示店铺系统命令
class showUserShopCmds : public showCmds {
public:
    void showUserCmds();
};

//为用户展示用户信息系统命令
class showUserInfoCmds : public showCmds {
public:
    void showUserCmds();
};

//为用户展示接口系统命令
class showUserInterfaceCmds : public showCmds {
public:
    void showUserCmds();
};

//为用户展示购物车系统命令
class showUserCartCmds : public showCmds {
public:
    void showUserCmds();
};

//为用户展示订单系统命令
class showUserOrderCmds : public showCmds {
public:
    void showUserCmds();
};

//本类中具体要完成的命令
class ConcreteCommands {
private:
    vector<string> _concreteCommands;
public:
    // 获取现存命令系统名称
    const vector<string> &getConcreteCommands() const {return _concreteCommands;}

    // 设置现存命令系统
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
    // 展示现存命令系统
    void displayExistingCommands();
};
// 初始化数据
void Initial();

#endif //DESIGNPATTERN_2021_WELCOME_H
