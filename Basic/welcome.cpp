#include "welcome.h"

using namespace std;

void showUserShopCmds::showUserCmds() {
    cout << endl;
    cout << "欢迎您使用天猫双十一购物节店铺板块功能！" << endl;
    cout << "1 - 查看所有店铺" << endl;
    cout << "2 - 评价指定ID店铺" << endl;
    cout << "3 - 根据评分筛选店铺" << endl;
    cout << "4 - 查看指定店铺详细信息" << endl;
    cout << "5 - 查看所有店铺商品列表" << endl;
    cout << "6 - 查看指定ID店铺商品列表" << endl;
    cout << "0 - 退出" << endl;
}

void showUserInfoCmds::showUserCmds() {
    cout << endl;
    cout << "您正在查看您的用户信息！" << endl;
    cout << "1 - 设置用户信息" << endl;
    cout << "2 - 查看用户信息" << endl;
    cout << "3 - 修改用户信息" << endl;
    cout << "0 - 退出" << endl;
}

void showUserCartCmds::showUserCmds() {
    cout << endl;
    cout << "您正在查看您的购物车信息！" << endl;
    cout << "1 - 查看购物车" << endl;
    cout << "2 - 将指定商品加入购物车" << endl;
    cout << "3 - 删除购物车中指定商品" << endl;
    cout << "4 - 减少购物车中指定商品" << endl;
    cout << "5 - 结算购物车" << endl;
    cout << "0 - 退出" << endl;
}

void showUserInterfaceCmds::showUserCmds() {
    cout << endl;
    cout << "欢迎光临天猫双十一购物节！请选择操作！" << endl;
    cout << "1 - 用户信息" << endl;
    cout << "2 - 店铺" << endl;
    cout << "3 - 商品" << endl;
    cout << "4 - 活动与广告" << endl;
    cout << "5 - 购物车" << endl;
    cout << "6 - 查看订单列表" << endl;
    cout << "0 - 退出" << endl;
}

void showUserOrderCmds::showUserCmds() {
    cout << endl;
    cout << "您正在查看您的订单信息！" << endl;
    cout << "1 - 查看您进行中的订单" << endl;
    cout << "2 - 支付全部未支付的订单" << endl;
    cout << "3 - 查看所有订单" << endl;
    cout << "0 - 退出" << endl;
}

void showUserCmdsAdapter::displayExistingCommands() {
    vector<string> _AdapterCommands = {"用户命令", "店铺命令", "商品命令", "购物车命令", "订单命令"};
    concreteCommands.setConcreteCommands(_AdapterCommands);
    cout << "已有的用户可以使用的命令提示集合: " << endl;
    for (string _commands:concreteCommands.getConcreteCommands()) {
        cout << _commands << endl;
    }
}

void Initial() {
    shopInterface shopInterface;
    shopInterface.initialize();
}