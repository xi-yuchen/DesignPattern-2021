//
// Created by liruijie666 on 2021/10/31.
//
#include "CartInterface.h"

using namespace std;

void CartInterface::MainInterface(shopInterface shopInterface, Customer *customer, OrderInterface &orderInterface) {
    int choice_status, ID;
    showUserCartCmds showUserCartCmds;
    // 获取当前用户
    cart.setCustomer(customer);
    // 获取商店信息
    cart.setShopInterface(shopInterface);
    // 链接订单界面类
    cart.setOrderInterface(orderInterface);
    while (true) {
        showUserCartCmds.showUserCmds();
        cin >> choice_status;
        if (choice_status == 0)
            break;
        switch (choice_status) {
            case 1: {
                DisplayCart displayCart;
                displayCart.setCart(cart);
                displayCart.operation();
                break;
            }
            case 2: {
                cout << "请输入您要加入商品ID与数量: " << endl;
                int addCommodityID, addCommodityNum;
                cin >> addCommodityID >> addCommodityNum;
                // 执行添加商品Command
                AddCommodity addCommodity(addCommodityID, addCommodityNum);
                addCommodity.setCart(cart);
                addCommodity.operation();
                setCart(addCommodity.getCart());
                break;
            }
            case 3: {
                cout << "请输入您要删除商品的ID: " << endl;
                int removeCommodityID;
                cin >> removeCommodityID;
                // 执行移除商品Command
                RemoveCommodity removeCommodity(removeCommodityID);
                removeCommodity.setCart(cart);
                removeCommodity.operation();
                setCart(removeCommodity.getCart());
                break;
            }
            case 4: {
                cout << "请输入您要删除商品的ID与要减少的数量: " << endl;
                int removeCommodityID, removeCommodityNum;
                cin >> removeCommodityID >> removeCommodityNum;
                // 执行按一定数量移除商品Command
                RemoveSomeCommodity removeSomeCommodity(removeCommodityID, removeCommodityNum);
                removeSomeCommodity.setCart(cart);
                removeSomeCommodity.operation();
                setCart(removeSomeCommodity.getCart());
                break;
            }
            case 5: {
                int choiceSub5;
                int payCommodityID, payCommodityNum;
                cout << "1-全部结算 2-结算指定ID全部商品 3-结算指定ID商品指定数量: " << endl;
                cin >> choiceSub5;
                if (choiceSub5 == 1) {
                    // 执行全部结算Command
                    PayAll payAll;
                    payAll.setCart(cart);
                    payAll.operation();
                    setCart(payAll.getCart());
                    orderInterface.setOrderlist(cart.getOrderInterface().getOrderlist());
                } else if (choiceSub5 == 2) {
                    cout << "请输入要结算商品的ID: " << endl;
                    cin >> payCommodityID;
                    // 执行结算单件商品Command
                    PaySingleCommodity paySingleCommodity(payCommodityID);
                    paySingleCommodity.setCart(cart);
                    paySingleCommodity.operation();
                    setCart(paySingleCommodity.getCart());
                    orderInterface.setOrderlist(cart.getOrderInterface().getOrderlist());
                } else if (choiceSub5 == 3) {
                    cout << "请输入要结算商品的ID与数量: " << endl;
                    cin >> payCommodityID;
                    cin >> payCommodityNum;
                    // 执行按一定数量结算商品Command
                    PaySomeCommodity paySomeCommodity(payCommodityID, payCommodityNum);
                    paySomeCommodity.setCart(cart);
                    paySomeCommodity.operation();
                    setCart(paySomeCommodity.getCart());
                    orderInterface.setOrderlist(cart.getOrderInterface().getOrderlist());
                } else
                    cout << "该命令不存在!" << endl;
                break;
            }
            default:
                cout << "不存在的命令！请重新输入！" << endl;
                break;
        }
    }
}

