#include<iostream>
#include "Basic/welcome.h"
#include "Shop/shopInterface.h"
#include "Customer/CustomerMain.h"
#include "Commodity/CommodityInterface.h"
#include "AC_ADSystem/Facade.h"
#include "Cart/CartInterface.h"
#include "ChainOfResponsibility/ChainOfResponsibility.h"

using namespace std;

int main() {
    int loginStatus, choice, choiceSub1;
    showUserInterfaceCmds showUserInterfaceCmds;

    shopInterface shopInterface;
    shopInterface.initialize();

    // == 创建公共的顾客数据集合以供不同子系统和功能模块同时读取
    CustomerInterface customerInterface;
    CustomerSet *customerList = CustomerSet::getInstance();
    customerList->init();

    // == 创建公共的商品数据集合以供不同子系统和功能模块同时读取
    CommodityInterface commodityInterface;
    commodityInterface.Initialize(shopInterface);

    Facade facade;
    CartInterface cartInterface;
    OrderInterface orderInterface;

    AbstractLogger *normal_log = new NormalLogger;
    AbstractLogger *success_log = new SuccessLogger;
    AbstractLogger *error_log = new ErrorLogger;
    normal_log->SetNextLogger(success_log);
    success_log->SetNextLogger(error_log);
    while (true) {
        normal_log->writeLog(1);
        cout << "欢迎来到天猫双十一购物节！请选择您的身份！1 - 顾客 & 2 - 商家 & 0 - 退出" << endl;
        cin >> loginStatus;
        if (loginStatus == 1) {
            while (true) {
                showUserInterfaceCmds.showUserCmds();
                cin >> choiceSub1;
                if (choiceSub1 == 0) {
                    normal_log->writeLog(1);
                    break;
                }
                switch (choiceSub1) {
                    case 1: {
                        customerInterface.setCustomerSet(customerList);
                        customerInterface.CustomerMain();
                        normal_log->writeLog(2);
                        break;
                    }
                    case 2: {
                        shopInterface.mainInterface(customerList->getCustomer());
                        normal_log->writeLog(2);
                        break;
                    }
                    case 3: {
                        cout << "欢迎您，您正在查看本店货物信息一览大全！" << endl;
                        shopInterface.showCommodityList(shopInterface.getCommodityList());
                        normal_log->writeLog(2);
                        break;
                    }
                    case 4: {
                        // 浏览当前已有的广告和活动
                        facade.BrowseAd();
                        facade.BrowseAc();
                        normal_log->writeLog(2);
                        break;
                    }
                    case 5: {
                        cartInterface.MainInterface(shopInterface, customerList->getCustomer(), orderInterface);
                        normal_log->writeLog(2);
                        break;
                    }
                    case 6: {
                        orderInterface.MainInterface(customerList->getCustomer());
                        normal_log->writeLog(2);
                        break;
                    }
                    case 0: {
                        break;
                    }
                    default: {
                        cout << "不存在的指令！请重新输入！" << endl;
                        normal_log->writeLog(3);
                        break;
                    }
                }
            }
        } else if (loginStatus == 0) {
            normal_log->writeLog(2);
            break;
        } else {
            cout << "您的选项无效，请重新输入！" << endl;
            normal_log->writeLog(3);
            cin >> choice;
        }
    }
    return 0;
}
