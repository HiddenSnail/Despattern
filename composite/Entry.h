//
// Created by 蜗牛 on 2016/11/8.
//

#ifndef COMPOSITE_ENTRY_H
#define COMPOSITE_ENTRY_H

#include <iostream>
#include <string>

class Entry {
protected:
    bool isImportant = false;
public:
    virtual ~Entry(){};
    virtual std::string getName() = 0;
    virtual int getSize() = 0;
    virtual void printList(std::string prefix) = 0;
    virtual void printList() {std::cout << std::endl;}
    virtual Entry* remove() = 0;
    virtual void update(bool signal) = 0;
};



#endif //COMPOSITE_ENTRY_H
