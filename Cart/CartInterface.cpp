//
// Created by liruijie666 on 2021/10/31.
//
#include "CartInterface.h"

using namespace std;

void CartInterface::MainInterface(shopInterface shopInterface, Customer *customer) {
    int choice_status, ID;
    showUserCartCmds showUserCartCmds;
    cart.setCustomer(customer);
    cart.setShopInterface(shopInterface);
    while (true) {
        showUserCartCmds.showUserCmds();
        cin >> choice_status;
        if (choice_status == 0)
            break;
        switch (choice_status) {
            case 1: {
                cart.display();
                break;
            }
            case 2: {
                cout << "请输入您要加入商品ID与数量: " << endl;
                int addCommodityID, addCommodityNum;
                cin >> addCommodityID >> addCommodityNum;
                cart.add(addCommodityID, addCommodityNum);
                break;
            }
            case 3: {
                cout << "请输入您要删除商品的ID: " << endl;
                int removeCommodityID;
                cin >> removeCommodityID;
                cart.remove(removeCommodityID);
                break;
            }
            case 4: {
                cout << "请输入您要删除商品的ID与要减少的数量: " << endl;
                int removeCommodityID, removeCommodityNum;
                cin >> removeCommodityID >> removeCommodityNum;
                cart.remove(removeCommodityID, removeCommodityNum);
                break;
            }
            case 5: {
                int choiceSub5;
                int payCommodityID, payCommodityNum;
                cout << "1-全部结算 2-结算指定ID全部商品 3-结算指定ID商品指定数量: " << endl;
                cin >> choiceSub5;
                if (choiceSub5 == 1)
                    cart.pay();
                else if (choiceSub5 == 2) {
                    cout << "请输入要结算商品的ID: " << endl;
                    cin >> payCommodityID;
                    cart.pay(payCommodityID);
                } else if (choiceSub5 == 3) {
                    cout << "请输入要结算商品的ID与数量: " << endl;
                    cin >> payCommodityID;
                    cin >> payCommodityNum;
                    cart.pay(payCommodityID, payCommodityNum);
                } else
                    cout << "该命令不存在!" << endl;
                break;
            }
            case 6: {
                CalculateOptionalPrice calculateOptionalPrice;
                calculateOptionalPrice.setCart(cart);
                calculateOptionalPrice.setCustomer(customer);
                calculateOptionalPrice.operation();
                break;
            }
            default:
                cout << "不存在的命令！请重新输入！" << endl;
                break;
        }
    }
}

