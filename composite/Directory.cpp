//
// Created by 蜗牛 on 2016/11/8.
//

#include "Directory.h"
#include <typeinfo>

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

bool Directory::isDir() {
    return true;
}

Entry* Directory::add(Entry* e){
    for (int index = 0; index < dir.size();index++) {
        if (e->getName() == dir[index]->getName() && e->isDir() == dir[index]->isDir()) {
            std::string type;
            if (true == e->isDir()) {
                type = "directory";
            } else {
                type = "file";
            }
            std::cerr << "The [" << this->getName() << "] directory "
                      << "already exists the "<< type <<" with the name "
                      << "\"" <<  e->getName() << "\"!" << std::endl;
            return this;
        }
    }
    dir.push_back(e);
    return this;
}

void Directory::printList(std::string prefix) {
    std::ostringstream msg;
    msg << prefix << "/" << this->getName();
    prefix = msg.str(); //获取前缀
    std::cout << prefix << "["
              << this->getSize() << "]"
              << std::endl;

    int num = 0;
    while (dir.size() > num) {
        dir[num]->printList(prefix);
        num++;
    }
}

void Directory::printList() {
    printList("");
    Entry::printList();
}

Entry* Directory::remove(Entry *e) {
    for (int num = 0; num < dir.size(); num++) {
        if (e->getName() == dir[num]->getName()) {

            Entry* del = dir[num];
            dir[num] = dir.back();
            dir.pop_back(); //不需要释放指针所指的内容

            //递归删除directory
            if (true == del->isDir()) {
                Directory* temp = (Directory*)del;
                for (int index = 0; index < temp->dir.size(); index++) {
                    temp->remove(temp->dir[index]);
                }
            }
            delete del;
            return this;
        }
    }
    return this;
}

Entry* Directory::removeAll() {
    for (int index = 0; index < dir.size(); index++) {
        remove(dir[index]);
    }
    return this;
}

