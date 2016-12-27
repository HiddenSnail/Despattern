//
// Created by 蜗牛 on 2016/12/6.
//

#ifndef UNDOREDO_CUTCOMMAND_H
#define UNDOREDO_CUTCOMMAND_H

#include "ICommand.h"
#include <string>
#include <iostream>

class CutCommand: public ICommand {
private:
    std::string text;

public:
    CutCommand(std::string text) {
        this->text = text;
    }
    void execute();
    void undo();
    std::string getText();
    void setText(std::string text);
};


#endif //UNDOREDO_CUTCOMMAND_H
