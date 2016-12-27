//
// Created by 蜗牛 on 2016/12/6.
//

#ifndef UNDOREDO_BASECOMMANDMANAGER_H
#define UNDOREDO_BASECOMMANDMANAGER_H

#include "BaseCommand.h"

class BaseCommandManager {
public:
    virtual ~BaseCommandManager(){}
    virtual bool callCommand(BaseCommand* pcommand) = 0;
    virtual void clearAllCommands() = 0;
    virtual void undo() = 0;
    virtual bool canUndo() const = 0;
    virtual void redo() = 0;
    virtual bool canRedo() const = 0;
};


#endif //UNDOREDO_BASECOMMANDMANAGER_H
