//
// Created by 蜗牛 on 2016/11/8.
//

#ifndef COMPOSITE_FILE_H
#define COMPOSITE_FILE_H

#include "Entry.h"

class File: public Entry {
private:
    std::string name;
    int size;
public:
    File() {
        this->name = "untitle";
        this->size = 0;
    }
    File(std::string fname) {
        this->name = fname;
        this->size = 0;
    }
    File(std::string fname, int fsize) {
        if (fsize < 0) {
            std::clog << "The file size is unreasonable! "
                 << "Already change it to size of 0."<< std::endl;
            this->size = 0;
        } else {
            this->size = fsize;
        }
        this->name = fname;
    }
    std::string getName();
    int getSize();
    bool isDir();
    void printList(std::string prefix);
    void printList();
};


#endif //COMPOSITE_FILE_H
