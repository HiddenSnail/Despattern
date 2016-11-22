//
// Created by 蜗牛 on 2016/11/8.
//

#ifndef COMPOSITE_DIRECTORY_H
#define COMPOSITE_DIRECTORY_H

#include "Entry.h"
#include "File.h"
#include <sstream>
#include <vector>
#include "State.h"


class Directory: public Entry {
    friend class File;
private:
    std::string name;
    std::vector<Entry*> dir; //已定义出object
    State state; //observer中, subject状态
    virtual Entry* remove(Entry* upper);
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
    Entry* remove(std::string name);
    Entry* add(Entry* e);
    Entry* add(std::string name, int size);
};


#endif //COMPOSITE_DIRECTORY_H
