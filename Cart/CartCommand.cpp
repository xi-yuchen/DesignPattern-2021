//
// Created by Frederick Mo on 2021/10/25.
//

#include "CartCommand.h"

void CartCommand::setCart(Cart _cart) {
    cart = _cart;
}

void CartCommand::setCustomer(Customer *customer) {
    cart.setCustomer(customer);
}

void AddCommodity::operation() {
//    cout << "Operating add commodity command" << endl;
    cart.add(id, amount);
}

void RemoveCommodity::operation() {
    cart.remove(id);
}

void RemoveSomeCommodity::operation() {
    cart.remove(id, amount);
}

void DisplayCart::operation() {
    cart.display();
}

void PayAll::operation() {
    cart.pay();
}

void PaySingleCommodity::operation() {
    cart.pay(id);
}

void PaySomeCommodity::operation() {
    cart.pay(id, amount);
}

CalculateOptionalPrice::CalculateOptionalPrice() {
    setCommodities(cart.getCommodityList());
}

CalculateOptionalPrice::CalculateOptionalPrice(int id) {
    setCommodities(cart.getCommodityList(id));
}

CalculateOptionalPrice::CalculateOptionalPrice(int id, int amount) {
    setCommodities(cart.getCommodityList(id, amount));
}

void CalculateOptionalPrice::operation() {
    cart.calculateOptionalPrice(getCommodities());
}

void ExecuteCommands::setCart(Cart _cart) {
    cart = _cart;
}

void ExecuteCommands::addCommand(CartCommand *command) {
    commands.push_back(command);
}

void ExecuteCommands::removeCommand(CartCommand *command) {
    commands.remove(command);
}

void ExecuteCommands::execute() {
    for (auto command : commands) {
        command->setCart(cart);
        command->operation();
    }
    commands.clear();
}
