//
// Created by 蜗牛 on 2016/12/6.
//

#ifndef UNDOREDO_ABSTRACTUNDOABLEEDIT_H
#define UNDOREDO_ABSTRACTUNDOABLEEDIT_H

#include "UndoableEdit.h"

//class AbstractUndoableEdit: public UndoableEdit {
//protected:
//    std::string undoName;
//    std::string redoName;
//private:
//    bool hasBeenDone;
//    bool alive;
//public:
//    AbstractUndoableEdit() {
//        hasBeenDone = true;
//        alive = true;
//    }
//    virtual ~AbstractUndoableEdit() {}
//    void undo();
//    bool canUndo();
//    void redo();
//    bool canRedo();
//    void die();
//    virtual void addEdit(UndoableEdit anEdit) = 0;
//    virtual bool isSignificant() = 0;
//    virtual std::string getPresentationName() = 0;
//    virtual std::string getUndoPresentationName() = 0;
//    virtual std::string getRedoPresentationName() = 0;
//    virtual std::string toString() = 0;
//};


#endif //UNDOREDO_ABSTRACTUNDOABLEEDIT_H
