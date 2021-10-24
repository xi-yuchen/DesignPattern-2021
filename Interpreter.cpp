#include "Interpreter.h"

#include "ActivitySystem.h"
#include <iostream>
using namespace std;

Interpreter::Interpreter()
{
    AcSystemInstance = ActivitySystem::GetAcSystemInstance();
}

void Interpreter::MakeInterpretation(string Code)
{
    if (Code.length() < 2)
        return;

    if (Code[0] == '1')
    {
        if (Code[1] == '1')
        {
            cout << "最优活动类别为打折类，具体配置如下：" << endl;
            for (int i = 2; i < Code.length(); i++)
            {
                if (Code[i] == 120)
                {
                    cout << "###第" << i-1 << "件商品不活动" << endl;
                    continue;
                }
                cout << "###第" << i-1 << "件商品使用活动为：" << endl;
                AcSystemInstance->PrintAc_D(Code[i]);
            }
        }
        else if (Code[1] == '2')
        {
            if (Code[2] == 120)
            {
                cout << "没有优惠活动！" << endl;
            }
            else
            {
                cout << "最优活动类别为满减类，最优活动为：" << endl;
                AcSystemInstance->PrintAc_F(Code[2]);
            }
        }

    }
    else if (Code[0] == '2')
    {
        cout << "推荐活动为：" << endl;

        for (int i = 2; i < Code.length(); i++)
        {
            AcSystemInstance->PrintAc_D(Code[i]);
        }
    }
}
