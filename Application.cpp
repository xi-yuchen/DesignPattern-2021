#include<iostream>
#include "Welcome/welcome.h"
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
    // == 创建公共店铺类的接口类以供不同子系统和功能模块同时读取
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

    // 初始化三级责任链模式的所有节点
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
                /*
                 * 设计模式：依赖注入 Dependence Injection
                 * 一个类的接口函数调用另一个类，使得在业务逻辑层面，调用类成为客户端client，被调用类成为服务器server。
                 * 依赖注入可以使用3种方式实现：通过参数传入、通过构造函数传入、setter函数
                 * 主过程内使用了通过参数传入的方式，然后进入具体函数调用后，即可使用通过构造函数传入、setter函数等完成。
                 */
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
