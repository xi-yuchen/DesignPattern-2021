//
// Created by liruijie666 on 2021/11/3.
//
#include "ChainOfResponsibility.h"

void NormalLogger::writeLog(int level) {
    if (level == 1)
        cout << "日志: 目前系统正常运行。" << endl;
    else
        _nextLogger->writeLog(level);
}

void SuccessLogger::writeLog(int level) {
    if (level == 2)
        cout << "系统日志: 用户操作成功。" << endl;
    else
        _nextLogger->writeLog(level);
}

void ErrorLogger::writeLog(int level) {
    if (level == 3)
        cout << "系统日志: 用户输入命令错误。" << endl;
    else
        _nextLogger->writeLog(level);
}
