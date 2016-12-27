//
// Created by 蜗牛 on 2016/12/6.
//

#include "DelCommand.h"

void DelCommand::execute() {
    std::cout << "Delete text: " << text << std::endl;
}

void DelCommand::undo() {
    std::cout << "Undo delete text: " << text << std::endl;
}

std::string DelCommand::getText() {
    return text;
}

void DelCommand::setText(std::string text) {
    this->text = text;
}