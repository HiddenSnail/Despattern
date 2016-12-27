//
// Created by 蜗牛 on 2016/12/6.
//

#ifndef UNDOREDO_MACROCOMMAND_H
#define UNDOREDO_MACROCOMMAND_H


#include "BaseCommand.h"

class MacroCommand: public BaseCommand {
public:
    MacroCommand() {}
    ~MacroCommand();

    virtual bool execute();
    virtual bool unExecute();

    void addCommand(BaseCommand* pCommand);
    void deleteCommand(BaseCommand* pCommand);

private:
    MacroCommand(const MacroCommand& rhs);
    MacroCommand& operator=(const MacroCommand& rhs);

private:
    std::vector<BaseCommand*> vecCommands;
};


#endif //UNDOREDO_MACROCOMMAND_H
