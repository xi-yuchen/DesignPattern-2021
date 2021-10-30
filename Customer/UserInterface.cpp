//
// Created by TJ_Lty on 2021/10/23.
//

#include "Information.h"
#include "UserInterface.h"
#include <iomanip>
#include <iostream>

using namespace std;

void CustomerInterface::setUserInformation() {
    VirtualCustomerInformationSetter setter(this->customer->getInfo());
    string name;
    string phone;
    string email;
    cout << "现在开始设置用户信息" << endl;
    cout << "请输入用户姓名:";
    cin >> name;
    setter.setName(name);
    cout << "请输入用户手机号";
    cin >> phone;
    setter.setPhone(phone);
    cout << "请输入用户邮箱";
    cin >> email;
    setter.setEmail(email);
    setter.setId((int) rand());
    setter.setPoints(0);
    auto *oldInfo = new CustomerInformation(*(this->customer->getInfo()));
    CustomerInformationOriginator originator{};
    originator.setState(oldInfo);
    customer->getCareTaker()->add(originator.saveStateToMemento());
}

void CustomerInterface::showUserInformation() {
    VirtualCustomerInformationReader reader(this->customer->getInfo());
    cout << "现在开始显示用户信息" << endl;
    cout << setw(5) << "ID" << ":" << reader.getID() << endl;
    cout << setw(5) << "姓名" << ":" << reader.getName() << endl;
    cout << setw(5) << "电话" << ":" << reader.getPhone() << endl;
    cout << setw(5) << "邮箱" << ":" << reader.getEmail() << endl;
    cout << setw(5) << "积分" << ":" << reader.getPoints() << endl;
    cout << setw(5) << "等级" << ":" << reader.getLevel() << endl;
}

void CustomerInterface::changeUserInformation() {
    VirtualCustomerInformationSetter setter(this->customer->getInfo());
    string name;
    string phone;
    string email;
    auto *oldInfo = new CustomerInformation(*(this->customer->getInfo()));
    VirtualCustomerInformationSetter oldSetter(CustomerInformation);
    cout << "现在开始更改用户信息,如有关项目无需更改请输入/" << endl;
    cout << "请输入用户姓名:";
    cin >> name;
    if (name != "/")
        setter.setName(name);
    cout << "请输入用户手机号";
    cin >> phone;
    if (phone != "/")
        setter.setPhone(phone);
    cout << "请输入用户邮箱";
    if (email != "/")
        cin >> email;
    setter.setEmail(email);
    cout << "修改完成" << endl;
    if (name == "/" && phone == "/" && email == "/") {
        delete oldInfo;
        return;
    }
    CustomerInformationOriginator originator{};
    originator.setState(oldInfo);
    customer->getCareTaker()->add(originator.saveStateToMemento());
}

void CustomerInterface::rollback() {
    cout << "确认修改您的信息吗？y/n";
    char check;
    cin >> check;
    if (check == 'y')
        return;
    auto *originator = new CustomerInformationOriginator();
    originator->getStateFromMemento(this->customer->getCareTaker()->pop());
    VirtualCustomerInformationSetter setter(this->customer->getInfo());
    setter.copy(originator->getstate());
    cout << "回滚完成" << endl;
}

Customer *CustomerInterface::getCustomer() {
    return this->customer;
}

void CustomerInterface::mainInterface() {
    int choice;
    VirtualCustomerInformationReader reader(customer->getInfo());
    showUserInfoCmds showUserInfoCmds;
    if (reader.getName() == "")
        setUserInformation();
    while (true) {
        showUserInfoCmds.showUserCmds();
        cin >> choice;
        if (choice == 0)
            break;
        switch (choice) {
            case 1:
                setUserInformation();
                break;
            case 2:
                showUserInformation();
                break;
            case 3:
                changeUserInformation();
                showUserInformation();
                rollback();
                showUserInformation();
                break;
            default:
                cout << "不存在的指令！请重新输入！" << endl;
                break;
        }
    }
}
//    this->setUserInformation();
//    cout << endl;
//    this->showUserInformation();
//    cout << endl;
//    this->changeUserInformation();
//    cout << endl;
//    this->showUserInformation();
//    cout << endl;
//    this->rollback();
//    cout << endl;
//    this->showUserInformation();

