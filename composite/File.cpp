//
// Created by 蜗牛 on 2016/11/8.
//

#include "File.h"
int File::VERNUM = 1;

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

Entry* File::remove() {
    Entry* del = this;
    delete del;
    std::cout << name << " 文件已成功删除！" << std::endl;
    return this;
}