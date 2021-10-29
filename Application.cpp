#include<iostream>
#include "Shop\shopInterface.h"

using namespace std;

int main() {
    int loginStatus;
    int choice;
    int choiceSub1;
    cout << "欢迎来到天猫双十一购物节！请选择您的身份！1 - 顾客 & 2 - 商家" << endl;
    cin >> loginStatus;
    while (true) {
        if (loginStatus == 1) {
            cin >> choiceSub1;
            if (choiceSub1 == 3) {
                shopInterface shopInterface;
                shopInterface.mainInterface();
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
