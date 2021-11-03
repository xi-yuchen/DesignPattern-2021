#ifndef DESIGNPATTERN_2021_CHAINOFRESPONSIBILITY_H
#define DESIGNPATTERN_2021_CHAINOFRESPONSIBILITY_H

#include <iostream>

using namespace std;

class AbstractLogger {
protected:
    AbstractLogger *_nextLogger;
public:
    AbstractLogger() { _nextLogger = nullptr; }

    virtual ~AbstractLogger() {}

    void SetNextLogger(AbstractLogger *logger) { _nextLogger = logger;}

    virtual void writeLog(int level) = 0;
};

class NormalLogger : public AbstractLogger {
    virtual void writeLog(int level);
};

class ErrorLogger : public AbstractLogger {
    virtual void writeLog(int level);
};

class SuccessLogger : public AbstractLogger {
    virtual void writeLog(int level);
};

#endif //DESIGNPATTERN_2021_CHAINOFRESPONSIBILITY_H
