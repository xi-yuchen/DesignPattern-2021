//
// Created by TJ_Lty on 2021/10/29.
//

#include<iostream>
#include<iomanip>
#include"Customer.h"
#include"Customers.h"
using namespace std;

void ShowInformation(){
    cout<<1;
    CustomerSet* customers= CustomerSet::getInstance();
    cout<<1;
    Customer* customer=customers->getCustomer();
    VirtualCustomerInformationReader* reader=customer->getCustomerReader();
    cout<<"当前用户:"<<endl;
    cout <<"ID " << ":" << reader->getID() << endl;
    cout << setw(5) << "姓名" << ":" << reader->getName() << endl;
    cout << setw(5) << "电话" << ":" << reader->getPhone() << endl;
    cout << setw(5) << "邮箱" << ":" << reader->getEmail() << endl;
    cout << setw(5) << "积分" << ":" << reader->getPoints() << endl;
    cout << setw(5) << "等级" << ":" << reader->getLevel() << endl;
}
void ShowCustomerList(){
    auto customers= CustomerSet::getInstance()->getCustomers();
    int index=0;
    for(auto customer:customers){
        cout << setw(5) << index++ << ":" << customer->getCustomerReader()->getName()<<"   "<<customer->getCustomerReader()->getID()<< endl;
    }
}

void ShowOperation(){
    cout<<"0 : 显示当前用户信息"<<endl;
    cout<<"1 : 新建用户"<<endl;
    cout<<"2 : 退出当前用户"<<endl;
    cout<<"3 : 切换用户"<<endl;
    cout<<"4 : 修改当前用户信息"<<endl;
    cout<<"5 : 回滚当前用户信息"<<endl;
    cout<<"6 : 退出用户系统"<<endl;
}

void DeleteCustomer(){

}

void AddCustomer(){
    CustomerSet* customers= CustomerSet::getInstance();
    auto welcome=new WelcomeMessage();
    AbstractCustomerBuilder* builder=new NormalCustomerBuilder;
    CustomerDirector::makeCustomer(builder);
    builder->getCustomer()->inputInformation();
    welcome->addCustomer(builder->getCustomer());
    customers->addCustomer(builder->getCustomer());
}

void ChangeInfo(){

}
void InitCustomers(){
    CustomerSet* customers= CustomerSet::getInstance();
    auto* customer=customers->getCustomer();
    auto welcome=new WelcomeMessage();
    AbstractCustomerBuilder* builder=new NormalCustomerBuilder;
    CustomerDirector::makeCustomer(builder);
    builder->getCustomer()->inputInformation();
}
void CustomerMain(){
    cout<<"welcome"<<endl;
    AbstractCustomerEvent* welcome=new WelcomeMessage();
    CustomerSet* customers= CustomerSet::getInstance();
    customers->init();
    cout<<"1"<<endl;
    while(1){
        ShowInformation();
        cout<<endl;
        ShowOperation();
        cout<<"请选择操作"<<endl;
        int op;
        cin>>op;
        if(op==0){
            ShowInformation();
        }else if(op==1){
            AbstractCustomerBuilder* builder=new NormalCustomerBuilder;
            CustomerDirector::makeCustomer(builder);
            builder->getCustomer()->inputInformation();
            welcome->addCustomer(builder->getCustomer());
            customers->addCustomer(builder->getCustomer());
        }else if(op==2){
            if(customers->getCustomer()->getCustomerReader()->getID()==0)
                cout<<"当前未登录"<<endl;
            else {
                welcome->deleteCustomer(customers->getCustomer());
                customers->deleteCustomer();
            }
        }else if(op==3){
            if(customers->getCustomer()->getCustomerReader()->getID()==0)
                cout<<"当前未登录"<<endl;
            else {
                ShowCustomerList();
                cout << "请输入:";
                int i;
                cin >> i;
                if (!customers->switchCustomer(i)) {
                    cout << "编号输入错误" << endl;
                }
            }
        }else if(op==4){
            if(customers->getCustomer()->getCustomerReader()->getID()==0)
                cout<<"当前未登录"<<endl;
            else
                customers->getCustomer()->updateInformation();
        }else if(op==5){
            if(customers->getCustomer()->getCustomerReader()->getID()==0)
                cout<<"当前未登录"<<endl;
            else
                customers->getCustomer()->rollback();
        }else if(op==6)
            break;
    }
//    CustomerSet* customers = CustomerSet::getInstance();
//    auto* customer=customers->getCustomer();
//
//    AbstractCustomerBuilder* builder=new NormalCustomerBuilder;
//    CustomerDirector::makeCustomer(builder);
//    builder->getCustomer()->inputInformation();
//
//
//    welcome->addCustomer(builder->getCustomer());
//    customers->addCustomer(builder->getCustomer());
//
//    builder=new VipCustomerBuilder;
//    CustomerDirector::makeCustomer(builder);
//    builder->getCustomer()->inputInformation();
//
//    welcome->addCustomer(builder->getCustomer());
//    customers->addCustomer(builder->getCustomer());
//
//    Customer* customer= customers->getCustomer();
//    CommodityInformationReader* reader=customer->getCommodityReader();
//    reader->setCommodityInformation()
//    cout<<"helloworld"<<endl;
}

int main(){
    CustomerMain();
}