//
// Created by Frederick Mo on 2021/10/25.
//

#include "CartCommand.h"

void CartCommand::setCart(Cart *cart) {
    this->cart = cart;
}

void CartCommand::setCustomer() {
    cart->setCustomer();
}

void AddCommodity::operation() {
//    cout << "Operating add commodity command" << endl;
    cart->add(id, amount);
}

void RemoveCommodity::operation() {
    cart->remove(id);
}

void RemoveSomeCommodity::operation() {
    cart->remove(id, amount);
}

void DisplayCart::operation() {
    cart->display();
}

void PayAll::operation() {
    cart->pay();
}

void PaySingleCommodity::operation() {
    cart->pay(id);
}

void PaySomeCommodity::operation() {
    cart->pay(id, amount);
}

CalculateOptionalPrice::CalculateOptionalPrice() {
    commodities = cart->getCommodity();
}

CalculateOptionalPrice::CalculateOptionalPrice(int id) {
    commodities = cart->getCommodity(id);
}

CalculateOptionalPrice::CalculateOptionalPrice(int id, int amount) {
    commodities = cart->getCommodity(id, amount);
}

void CalculateOptionalPrice::operation() {
    cart->calculateOptionalPrice(commodities);
}

void ExecuteCommands::setCart(Cart *cart) {
    this->cart = cart;
}

void ExecuteCommands::addCommand(CartCommand *command) {
    commands.push_back(command);
    if (!commands.empty()) {
        this->cart->setCustomer();
    }
}

void ExecuteCommands::removeCommand(CartCommand *command) {
    commands.remove(command);
}

void ExecuteCommands::execute() {
    for (auto command : commands) {
        (*command).setCart(this->cart);
        (*command).operation();
    }
    commands.clear();
}
