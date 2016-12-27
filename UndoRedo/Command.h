//
// Created by 蜗牛 on 2016/12/6.
//

#ifndef UNDOREDO_COMMAND_H
#define UNDOREDO_COMMAND_H

#include "BaseCommand.h"
#include "BaseCommandReceiver.h"

class Command: public BaseCommand {
public:
    Command();
    virtual ~Command();
    virtual bool execute();
    virtual bool unExecute();

    void setReceiver(BaseCommandReceiver* pReceiver, bool bAutoDelete = true);

private:
    Command(const Command& rhs);
    Command& operator=(const Command& rhs);

protected:
    BaseCommandReceiver* p_receiver;
    bool b_autoDeleteReceiver;
};


#endif //UNDOREDO_COMMAND_H
