//
// Created by 蜗牛 on 2016/12/6.
//

#include "CutCommand.h"

void CutCommand::execute() {
    std::cout << "Cut some text: " << text << std::endl;
}

void CutCommand::undo() {
    std::cout << "Undo cut some text: " << text << std::endl;
}

std::string CutCommand::getText() {
    return text;
}

void CutCommand::setText(std::string text) {
    this->text = text;
}
