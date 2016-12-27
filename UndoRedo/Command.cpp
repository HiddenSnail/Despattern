//
// Created by 蜗牛 on 2016/12/6.
//

#include "Command.h"

RegisterCommandClass<Command> registerCommandClass("Command");

Command::Command(): p_receiver(NULL), b_autoDeleteReceiver(true){}

Command::~Command() {
    if (b_autoDeleteReceiver && p_receiver) {
        delete p_receiver;
        p_receiver = NULL;
    }
}

bool Command::execute() {
    if (p_receiver) {
        return p_receiver->action(false);
    }

    return false;
}

bool Command::unExecute() {
    if (p_receiver) {
        return p_receiver->action(true);
    }

    return false;
}

void Command::setReceiver(BaseCommandReceiver *pReceiver, bool bAutoDelete) {
    p_receiver = pReceiver;
    b_autoDeleteReceiver = bAutoDelete;
}

