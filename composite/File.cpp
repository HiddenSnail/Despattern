//
// Created by 蜗牛 on 2016/11/8.
//

#include "File.h"

std::string File::getName() {
    return this->name;
}

int File::getSize() {
    return this->size;
}

void File::printList(std::string prefix) {

    std::cout << prefix << "/"
              << getName() << "("
              << getSize() << ")"
              << std::endl;
}

void File::printList() {
    printList("");
    Entry::printList();
}

Entry* File::remove(Entry* upper) {
    Directory* parent = (Directory*)upper;
    File* del = this;
    for (int index = 0; parent->dir.size(); index++) {
        if (parent->dir[index] == this) {
            parent->dir[index] = parent->dir.back();
            parent->dir.pop_back();
            delete(del);
            return this;
        }
    }
    //删除失败
    std::cout << "删除失败！" << std::endl;
    return NULL;
}