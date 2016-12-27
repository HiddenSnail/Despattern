//
// Created by 蜗牛 on 2016/12/6.
//

#ifndef UNDOREDO_COMPOUNDEDIT_H
#define UNDOREDO_COMPOUNDEDIT_H

#include "AbstractUndoableEdit.h"
#include <vector>

//class CompoundEdit: public AbstractUndoableEdit {
//protected:
//    std::vector<UndoableEdit*> edits;
//    bool inProgress;
//public:
//    void undo();
//    bool canUndo();
//    void redo();
//    bool canRedo();
//    void die();
//    virtual void addEdit(UndoableEdit anEdit){}
//    virtual bool isSignificant(){}
//    virtual std::string getPresentationName(){}
//    virtual std::string getUndoPresentationName(){}
//    virtual std::string getRedoPresentationName(){}
//    virtual std::string toString(){}
//
//    UndoableEdit* lastEdit();
//    void end();
//    bool isProgress();
//};


#endif //UNDOREDO_COMPOUNDEDIT_H
