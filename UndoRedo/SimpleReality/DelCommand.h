//
// Created by 蜗牛 on 2016/12/6.
//

#ifndef UNDOREDO_DELCOMMAND_H
#define UNDOREDO_DELCOMMAND_H

#include "ICommand.h"
#include <string>
#include <iostream>

class DelCommand: public ICommand {
private:
    std::string text;
public:
    void execute();
    void undo();
    std::string getText();
    void setText(std::string text);
};


#endif //UNDOREDO_DELCOMMAND_H
