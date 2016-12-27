//
// Created by 蜗牛 on 2016/12/6.
//

#ifndef UNDOREDO_ICOMMAND_H
#define UNDOREDO_ICOMMAND_H


class ICommand {
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
};


#endif //UNDOREDO_ICOMMAND_H
