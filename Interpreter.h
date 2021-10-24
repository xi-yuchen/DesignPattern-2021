#pragma once
#include <string>
using namespace std;

//使用设计模式：解释器

class ActivitySystem;

class Interpreter
{
public:

    Interpreter();

    void MakeInterpretation(string Code);//解释Code含义

private:
    
    ActivitySystem* AcSystemInstance;
};
