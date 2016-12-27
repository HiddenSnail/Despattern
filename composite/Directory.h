//
// Created by 蜗牛 on 2016/11/8.
//

#ifndef COMPOSITE_DIRECTORY_H
#define COMPOSITE_DIRECTORY_H

#include "Entry.h"
#include "File.h"
#include <sstream>
#include <vector>


class Directory: public Entry {
private:
    static int VERNUM;
    std::string name;
    std::vector<Entry*> dir; //已定义出object
    virtual Entry* remove();
public:
    Directory() {
        this->name = "directory" + std::to_string(VERNUM);
        VERNUM++;
    }
    Directory(std::string fname) {
        this->name = fname;
    }

    std::string getName();
    int getSize();
    void printList(std::string prefix);
    void printList();
    Entry* remove(std::string name);    //移除文件(文件夹)的接口
    Entry* add(Entry* e);

    void update(bool signal);
    void notify();
};

#endif //COMPOSITE_DIRECTORY_H
