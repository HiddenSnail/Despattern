//
// Created by 蜗牛 on 2016/12/6.
//

#include "MacroCommand.h"

//RegisterCommandClass<MacroCommand> registerCommandClass("MacroCommand");

MacroCommand::~MacroCommand() {
    std::vector<BaseCommand*>::iterator it;
    for (it = vecCommands.begin(); it != vecCommands.end(); it++) {
        delete (*it);
    }
    vecCommands.clear();
}

bool MacroCommand::execute() {
    for (int i = 0;i < vecCommands.size(); i++) {
        BaseCommand* pCommand = vecCommands[i];
        if (!pCommand->execute()) {
            return false;
        }
    }
    return true;
}

bool MacroCommand::unExecute() {
    for (int i = vecCommands.size()-1; i >= 0; i--) {
        BaseCommand* pCommand = vecCommands[i];
        if (!pCommand->unExecute()) {
            return false;
        }
    }
    return true;
}

void MacroCommand::addCommand(BaseCommand *pCommand) {
    if (pCommand) {
        vecCommands.push_back(pCommand);
    }
}

void MacroCommand::deleteCommand(BaseCommand *pCommand) {
    if (pCommand) {
        vecCommands.erase(std::remove(vecCommands.begin(), vecCommands.end(), pCommand));
    }
}