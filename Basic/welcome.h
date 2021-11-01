//
// Created by liruijie666 on 2021/10/30.
//

#ifndef DESIGNPATTERN_2021_WELCOME_H
#define DESIGNPATTERN_2021_WELCOME_H

#include <iostream>
#include "../Shop/shopInterface.h"
#include "../Customer/Customer.h"

using namespace std;

class showCmds {
public:
    virtual void showUserCmds() = 0;
};

class showUserShopCmds : public showCmds {
public:
    void showUserCmds();
};

class showUserInfoCmds : public showCmds {
public:
    void showUserCmds();
};

class showUserInterfaceCmds : public showCmds {
public:
    void showUserCmds();
};

class showUserCartCmds : public showCmds {
public:
    void showUserCmds();
};

void Initial();
#endif //DESIGNPATTERN_2021_WELCOME_H
