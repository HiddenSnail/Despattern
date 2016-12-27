//
// Created by 蜗牛 on 2016/12/6.
//

#ifndef UNDOREDO_BASECOMMANDRECEIVER_H
#define UNDOREDO_BASECOMMANDRECEIVER_H

#include <string>
#include "Factory.h"

class BaseCommandReceiver {
public:
    virtual ~BaseCommandReceiver() {}
    virtual bool action(bool bUndo) = 0;
    static BaseCommandReceiver* createBaseCommandReceiver(const std::string strCommandReceiver) {
        return Factory<BaseCommandReceiver, std::string>::instance()->createObject(strCommandReceiver);
    }
};

template <class DerivedCommandReceiver>
class RegisterCommandReceiverClass {
public:
    static BaseCommandReceiver* create() {
        return new DerivedCommandReceiver;
    }

    RegisterCommandReceiverClass(const std::string& strId) {
        Factory<BaseCommandReceiver, std::string>::instance()->registerProduct(strId, RegisterCommandReceiverClass::create);
    }
};


#endif //UNDOREDO_BASECOMMANDRECEIVER_H
