#include<iostream>
#include "UserInterface.h"

using namespace std;

int main() {
    int login_status;//区分商家端还是客户端的选项代码，1代表用户，2代表商家。

    //1 -> Users Mode, 2 -> Sellers Mode, 0 -> Exit, other code -> error message.
    while (1) {

        cout << "Welcome TMALL 11.11 Festival! You are? 1-User 2-Seller. Select your status to continue." << endl;

        cin >> login_status;

        if (login_status == 1) {
            /*
             * Client for users Code.
             */
            auto *a = new CustomerInterface();
            a->mainInterface();
            cout << "--用户信息展示--" << endl;
            a->showUserInformation();
            delete a;
        } else if (login_status == 2) {
            /*
             * Client for sellers Code.
             */
        } else if (login_status == 0) {
            break;
        } else {
            cout << "We have no such login status. Please try again." << endl;
        }
    }
    return 0;
}
