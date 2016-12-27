//
// Created by 蜗牛 on 2016/11/8.
//

#include "Directory.h"

int Directory::VERNUM = 1;

Entry* Directory::remove() {
    if(isImportant == true) {
        std::cout << name << " 文件夹是重要文件夹，删除失败" << std::endl;
        return NULL;
    }
    Entry* del = this;
    while(this->dir.size()) {
        this->dir.back()->remove();
        dir.pop_back();
    }
    delete del;
    std::cout << name << " 文件夹已成功删除！" << std::endl;
    return this;
}

Entry* Directory::remove(std::string name) {
    for(int index = 0; index < dir.size(); index++) {
        if (name == dir[index]->getName()) {
            Entry* target = dir[index];
            Entry* result = target->remove();
            if (result != NULL) {
                dir[index] = dir.back();
                dir.pop_back();
            }
            return result;
        }
    }
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
            std::cout << "The [" << this->getName() << "] directory "
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

void Directory::update(bool signal) {
    isImportant = signal;
    notify();
}

void Directory::notify() {
    for (int i = 0;i < dir.size();i++) {
        dir[i]->update(isImportant);
    }
}
