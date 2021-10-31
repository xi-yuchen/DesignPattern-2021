//
// Created by liruijie666 on 2021/10/30.
//
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

void showUserAddCartCmds::showUserCmds() {
    cout << endl;
    cout << "1 - 请输入商品ID与数量，将之加入购物车！" << endl;
    cout << "0 - 退出" << endl;
}

void showUserInterfaceCmds::showUserCmds() {
    cout << endl;
    cout << "欢迎光临天猫双十一购物节！请选择操作！" << endl;
    cout << "1 - 用户信息" << endl;
    cout << "2 - 店铺" << endl;
    cout << "3 - 商品" << endl;
    cout << "4 - 活动与广告" << endl;
    cout << "5 - 计算折扣与满减" << endl;
    cout << "6 - 将指定商品加入购物车" << endl;
    cout << "7 - 查看购物车" << endl;
    cout << "8 - 结算购物车" << endl;
    cout << "9 - 查看订单列表" << endl;
    cout << "0 - 退出" << endl;
}

void Initial() {
    shopInterface shopInterface;
    shopInterface.initialize();
}