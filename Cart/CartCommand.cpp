//
// Created by Frederick Mo on 2021/10/25.
//

#include "CartCommand.h"

void AddCommodity::operation() {
    cart->add(*commodity);
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

void ExecuteCommands::addCommand(CartCommand *command) {
    commands.push_back(command);
}

void ExecuteCommands::removeCommand(CartCommand *command) {
    commands.remove(command);
}

void ExecuteCommands::execute() {
    for (auto command : commands)
        command->operation();
}