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

bool File::isDir() {
    return false;
}

void File::printList(std::string prefix) {

    std::cout << prefix << "/" << getName() << "(" << getSize() << ")" << std::endl;
}

void File::printList() {
    printList("");
    Entry::printList();
}