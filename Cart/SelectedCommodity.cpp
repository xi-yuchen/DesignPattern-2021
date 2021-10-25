//
// Created by Frederick Mo on 2021/10/22.
//

#include "SelectedCommodity.h"

SelectedCommodity::SelectedCommodity(int id, string name, string type, int price, int amount) {
    this->id = id;
    this->name = name;
    this->type = type;
    this->price = price;
    this->amount = amount;
}

//SelectedCommodity::SelectedCommodity(SelectedCommodity &commodity) {
//    this->id = commodity.getID();
//    this->name = commodity.getName();
//    this->type = commodity.getType();
//    this->price = commodity.getPrice();
//    this->amount = commodity.getAmount();
//}

void SelectedCommodity::setAmount(int amount) {
    this->amount = amount;
}

void SelectedCommodity::add(int amount) {
    this->amount += amount;
}

bool SelectedCommodity::remove(int amount) {
    if (this->amount < amount)
        return false;
    this->amount -= amount;
    // 不知道自行删除能不能行？但是先这样写试试看
//    if (this->amount == 0)
//        this->cart->remove(this->getID());
    return true;
}

//void SelectedCommodity::setCart(Cart *cart) {
//    this->cart = cart;
//}

void SelectedCommodity::display() {
    cout << this->id << "\t" << this->name << "\t" << this->type << "\t" << this->price << "\t" << this->amount << endl;
}