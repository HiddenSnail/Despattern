//
// Created by 蜗牛 on 2016/12/7.
//

#ifndef UNDOREDO_PRINTCOMMAND_H
#define UNDOREDO_PRINTCOMMAND_H

#include "BaseCommand.h"
#include <iostream>

class PrintCommand: public BaseCommand {
    virtual ~PrintCommand();
    virtual bool execute() {
        std::cout << "print text!" << std::endl;
        return true;
    }

    virtual bool unExecute() {
        std::cout << "no print text!" << std::endl;
        return true;
    }
};


#endif //UNDOREDO_PRINTCOMMAND_H
