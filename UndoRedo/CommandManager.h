//
// Created by 蜗牛 on 2016/12/6.
//

#ifndef UNDOREDO_COMMANDMANAGER_H
#define UNDOREDO_COMMANDMANAGER_H

#include "BaseCommandManager.h"
#include <stack>
#include "Singleton.h"

class CommandManager: public BaseCommandManager{
    class UndoRedoStateInspector {
        friend class CommandManager;

    private:
        UndoRedoStateInspector(CommandManager* pCommandManager);
        ~UndoRedoStateInspector();

    private:
        CommandManager* p_commandManager;
        bool b_undoable;
        bool b_redoable;
    };

    friend class Singleton<CommandManager>;

private:
    std::stack<BaseCommand*> stackUndo;
    std::stack<BaseCommand*> stackRedo;

private:
    CommandManager(){}
    ~CommandManager();
    CommandManager(const CommandManager& rhs);
    CommandManager& operator=(const CommandManager& rhs);

    void pushUndoCommand(BaseCommand* pCommand);
    BaseCommand* popUndoCommand();
    void pushRedoCommand(BaseCommand* pCommand);
    BaseCommand* popRedoCommand();
    void deleteUndoCommands();
    void deleteRedoCommands();

public:
    static CommandManager* instance();
    bool callCommand(BaseCommand* pCommand);
    void clearAllCommands();
    void undo();
    bool canUndo() const;
    void redo();
    bool canRedo() const;

};


#endif //UNDOREDO_COMMANDMANAGER_H
