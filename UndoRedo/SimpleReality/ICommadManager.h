//
// Created by 蜗牛 on 2016/12/6.
//

#ifndef UNDOREDO_ICOMMADMANAGER_H
#define UNDOREDO_ICOMMADMANAGER_H

#include "ICommand.h"

class ICommadManager {
public:
    virtual void storeCommand(ICommand* cmd) = 0;
    virtual void clearAllCommnd() = 0;
    virtual void undo() = 0;
    virtual void redo() = 0;
};


#endif //UNDOREDO_ICOMMADMANAGER_H
