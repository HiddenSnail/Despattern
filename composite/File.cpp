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
    if(isImportant == true) {
        std::cout << name << " 文件夹是重要文件，删除失败" << std::endl;
        return NULL;
    }
    Entry* del = this;
    delete del;
    std::cout << name << " 文件已成功删除！" << std::endl;
    return this;
}

void File::update(bool signal) {
    this->isImportant = signal;
}