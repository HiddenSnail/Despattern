//
// Created by 蜗牛 on 2016/12/6.
//

#include "CommandHistoryManager.h"

void CommandHistoryManager::storeCommand(ICommand* cmd) {
    undoList.push_back(cmd);
}

void CommandHistoryManager::clearAllCommnd() {
    undoList.clear();
    redoList.clear();
}

void CommandHistoryManager::undo() {
    if (undoList.empty()) return;
    ICommand *cmd = undoList.back();
    cmd->undo();
    undoList.pop_back();
    redoList.push_back(cmd);
}
void CommandHistoryManager::redo() {
    if (redoList.empty()) return;
    ICommand *cmd = redoList.back();
    cmd->execute();
    redoList.pop_back();
    undoList.push_back(cmd);
}