//
// Created by 蜗牛 on 2016/11/8.
//

#include "Directory.h"

std::string Directory::getName() {
    return this->name;
}

int Directory::getSize() {
    int size = 0;
    for (int index = 0;index < dir.size();index++) {
        size += dir[index]->getSize();
    }
    return size;
}

void Directory::add(Entry* e){
    dir.push_back(e);
}

void Directory::printList(std::string prefix) {
    std::ostringstream msg;
    msg << prefix << "/" << this->getName();
    prefix = msg.str(); //获取前缀
    std::cout << prefix << "[" << this->getSize() << "]" << std::endl;

    int num = 0;
    while (dir.size() > num) {
        dir[num]->printList(prefix);
        num++;
    }
}

void Directory::printList() {
    printList("");
}