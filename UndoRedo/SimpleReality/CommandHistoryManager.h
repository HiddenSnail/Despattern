//
// Created by 蜗牛 on 2016/12/6.
//

#ifndef UNDOREDO_COMMANDHISTORYMANAGER_H
#define UNDOREDO_COMMANDHISTORYMANAGER_H

#include "ICommadManager.h"
#include <vector>

class CommandHistoryManager: public ICommadManager {
private:
    std::vector<ICommand*> undoList;
    std::vector<ICommand*> redoList;
public:
    void storeCommand(ICommand* cmd);
    void clearAllCommnd();
    void undo();
    void redo();
};


#endif //UNDOREDO_COMMANDHISTORYMANAGER_H
