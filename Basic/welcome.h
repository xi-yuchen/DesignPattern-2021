//
// Created by liruijie666 on 2021/10/30.
//

#ifndef DESIGNPATTERN_2021_WELCOME_H
#define DESIGNPATTERN_2021_WELCOME_H

#include <iostream>

using namespace std;

class showCmds {
public:
    virtual void showUserCmds() = 0;
};

class showUserShopCmds : public showCmds {
public:
    void showUserCmds();
};

#endif //DESIGNPATTERN_2021_WELCOME_H
