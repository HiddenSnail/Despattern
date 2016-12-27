//
// Created by 蜗牛 on 2016/12/6.
//

#include "CommandManager.h"

CommandManager::UndoRedoStateInspector::UndoRedoStateInspector(CommandManager *pCommandManager):
p_commandManager(pCommandManager), b_undoable(pCommandManager->canUndo()), b_redoable(pCommandManager->canRedo()){}

CommandManager::UndoRedoStateInspector::~UndoRedoStateInspector() {
//    if (b_undoable != p_commandManager->canUndo() || b_redoable != p_commandManager->canRedo()) {
//
//    }
}

CommandManager::~CommandManager() {
    clearAllCommands();
}

CommandManager* CommandManager::instance() {
    return Singleton<CommandManager>::instance();
}

bool CommandManager::callCommand(BaseCommand *pCommand) {
    UndoRedoStateInspector si(this);
    if (pCommand) {
        if (pCommand->execute()) {
            pushUndoCommand(pCommand);
            deleteRedoCommands();
            return true;
        }
        else {
            delete pCommand;
        }
    }
    return false;
}

void CommandManager::clearAllCommands() {
    UndoRedoStateInspector si(this);
    deleteUndoCommands();
    deleteRedoCommands();
}

void CommandManager::undo() {
    UndoRedoStateInspector si(this);
    BaseCommand* pCommand = popUndoCommand();
    if (pCommand) {
        if (pCommand->unExecute()) {
            pushRedoCommand(pCommand);
        } else {
            delete pCommand;
        }
    }
}

void CommandManager::redo() {
    UndoRedoStateInspector si(this);
    BaseCommand* pCommand = popRedoCommand();
    if (pCommand) {
        if (pCommand->execute()) {
            pushUndoCommand(pCommand);
        } else {
            delete  pCommand;
        }
    }
}

bool CommandManager::canUndo() const {
    return !stackUndo.empty();
}

bool CommandManager::canRedo() const {
    return !stackRedo.empty();
}

void CommandManager::pushUndoCommand(BaseCommand *pCommand) {
    if (pCommand) {
        stackUndo.push(pCommand);
    }
}

void CommandManager::pushRedoCommand(BaseCommand *pCommand) {
    if (pCommand) {
        stackRedo.push(pCommand);
    }
}

BaseCommand* CommandManager::popUndoCommand() {
    BaseCommand* pCommand = NULL;
    if (!stackUndo.empty()) {
        pCommand = stackUndo.top();
        stackUndo.pop();
    }
    return pCommand;
}

BaseCommand* CommandManager::popRedoCommand() {
    BaseCommand* pCommand = NULL;
    if (!stackRedo.empty()) {
        pCommand = stackRedo.top();
        stackRedo.pop();
    }
    return pCommand;
}

void CommandManager::deleteUndoCommands() {
    while (!stackUndo.empty()) {
        delete stackUndo.top();
        stackUndo.pop();
    }
}

void CommandManager::deleteRedoCommands() {
    while (!stackRedo.empty()) {
        delete stackRedo.top();
        stackRedo.pop();
    }
}