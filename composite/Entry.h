//
// Created by 蜗牛 on 2016/11/8.
//

#ifndef COMPOSITE_ENTRY_H
#define COMPOSITE_ENTRY_H

#include <iostream>
#include <string>

class Entry {
public:
    virtual ~Entry(){};
    virtual std::string getName() = 0;
    virtual int getSize() = 0;
    virtual void printList(std::string prefix) = 0;
    virtual void printList() {}
    virtual void add(Entry* e) {} //待修改
    virtual Entry* remove(Entry* e) {}; //待修改
    virtual bool isDir() = 0;
};



#endif //COMPOSITE_ENTRY_H
