//
// Created by 蜗牛 on 2016/12/6.
//

#ifndef UNDOREDO_BASECOMMAND_H
#define UNDOREDO_BASECOMMAND_H

#include "Factory.h"

class BaseCommand {
public:
    virtual ~BaseCommand(){}
    virtual bool execute() = 0;
    virtual bool unExecute() = 0;

    static BaseCommand* createCommand(const std::string& strCommand) {
        return Factory<BaseCommand, std::string>::instance()->createObject(strCommand);
    }
};

template <class DerivedCommand>
class RegisterCommandClass {
public:
    static BaseCommand* create() {
        return new DerivedCommand();
    }
    RegisterCommandClass(const std::string strId) {
        Factory<BaseCommand, std::string>::instance()->registerProduct(strId, RegisterCommandClass::create);
    }
};

#endif //UNDOREDO_BASECOMMAND_H
