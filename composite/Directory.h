//
// Created by 蜗牛 on 2016/11/8.
//

#ifndef COMPOSITE_DIRECTORY_H
#define COMPOSITE_DIRECTORY_H

#include "Entry.h"
#include <sstream>
#include <vector>

class Directory: public Entry {
private:
    std::string name;
    std::vector<Entry*> dir; //已定义出object
public:
    Directory() {
        this->name = "untitle";
    }
    Directory(std::string fname) {
        this->name = fname;
    }

    std::string getName();
    int getSize();
    void printList(std::string prefix);
    void printList();
    virtual void add(Entry* e);
};


#endif //COMPOSITE_DIRECTORY_H
