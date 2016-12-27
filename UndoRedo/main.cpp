#include <iostream>
#include "SimpleReality/DelCommand.h"
#include "SimpleReality/CutCommand.h"
#include "SimpleReality/CommandHistoryManager.h"
#include "PrintCommand.h"
#include "BaseCommand.h"

using namespace std;

int main() {
    CommandHistoryManager manager;
    for (int i = 0; i < 10; i++) {
        CutCommand* cmd = new CutCommand("article" + std::to_string(i+1));
        cmd->execute();
        manager.storeCommand(cmd);
    }

    for (int i = 0; i < 5;i++) {
        manager.undo();
    }

    for (int i = 0;i < 5;i++) {
        manager.redo();
    }
}