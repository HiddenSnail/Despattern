//
// Created by 蜗牛 on 2016/11/8.
//

#include "Directory.h"

Entry* Directory::remove(Entry* upper) {
    Directory* parent = (Directory*)upper;
    Directory* del = this;
    for (int index = 0; index < parent->dir.size(); index++) {
        if (parent->dir[index] == this) {
            parent->dir[index] = parent->dir.back();
            parent->dir.pop_back();
            //递归删除directory
            for (int it = 0; it < this->dir.size(); it++) {
                this->dir[it]->remove(this);
            }
            delete del;
            return this;
        }
    }

    std::cout << "删除失败" << std::endl;
    return NULL;
}


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


Entry* Directory::add(Entry* e){
    for (int index = 0; index < dir.size(); index++) {
        if (e->getName() == dir[index]->getName()) {
            std::cerr << "The [" << this->getName() << "] directory "
                      << "already exists the "<< "file or directory" <<" with the name "
                      << "\"" <<  e->getName() << "\"!" << std::endl;
            return NULL;
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

Entry* Directory::remove(std::string name) {
    for (int index = 0; index < dir.size(); index++) {
        if (name == dir[index]->getName()) {
            return dir[index]->remove(this);
        }
    }
}

Entry* Directory::add(std::string name, int size) {
    File* file = new File(name, size);
    return add(file);
}