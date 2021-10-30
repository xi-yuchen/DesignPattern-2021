#include<iostream>
#include "Basic/welcome.h"
#include "Shop/shopInterface.h"
#include "Customer/UserInterface.h"
#include "Commodity/CommodityInterface.h"
#include "AC_ADSystem/Facade.h"

using namespace std;

int main() {
    int loginStatus, choice, choiceSub1;
    showUserInterfaceCmds showUserInterfaceCmds;
    CustomerInterface customerInterface;
    shopInterface shopInterface;
    Facade facade;
    shopInterface.initialize();
    CommodityInterface commodityInterface;
    commodityInterface.Initialize(shopInterface);
    while (true) {
        cout << "欢迎来到天猫双十一购物节！请选择您的身份！1 - 顾客 & 2 - 商家 & 0 - 退出" << endl;
        cin >> loginStatus;
        if (loginStatus == 1) {
            while (true) {
                showUserInterfaceCmds.showUserCmds();
                cin >> choiceSub1;
                if (choiceSub1 == 0)
                    break;
                switch (choiceSub1) {
                    case 1: {
                        customerInterface.mainInterface();
                        break;
                    }
                    case 2: {
                        shopInterface.mainInterface(customerInterface.getCustomer());
                        break;
                    }
                    case 3: {
                        shopInterface.manageGoods(1, shopInterface);
                        break;
                    }
                    case 4: {
                        facade.BrowseAd();
                        facade.BrowseAc();
                        break;
                    }
                    case 5: {

                    }
                    case 6: {

                    }
                    case 7: {

                    }
                    case 8: {

                    }
                    case 9: {

                    }
                    case 0: {
                        break;
                    }
                    default: {
                        cout << "不存在的指令！请重新输入！" << endl;
                        break;
                    }
                }
            }
        } else if (loginStatus == 2) {

        } else if (loginStatus == 0)
            break;
        else {
            cout << "您的选项无效，请重新输入！" << endl;
            cin >> choice;
        }
    }
    return 0;
}
