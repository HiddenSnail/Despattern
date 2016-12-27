//
// Created by 蜗牛 on 2016/11/8.
//

#ifndef COMPOSITE_FILE_H
#define COMPOSITE_FILE_H

#include "Entry.h"
#include "Directory.h"

class File: public Entry {
private:
    static int VERNUM;
    std::string name;
    int size;
    virtual Entry* remove();
public:
    File() {
        this->name = "untitle" + std::to_string(VERNUM);
        this->size = 0;
        VERNUM++;
    }
    File(std::string fname) {
        if (fname == "") {
            this->name = "untitle" + std::to_string(VERNUM);
            VERNUM++;
        }
        else {
            this->name = fname;
        }
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

        if (fname == "") {
            this->name = "untitle" + std::to_string(VERNUM);
            VERNUM++;
        }
        else {
            this->name = fname;
        }
    }
    std::string getName();
    int getSize();
    void printList(std::string prefix);
    void printList();
    void update(bool signal);
};


#endif //COMPOSITE_FILE_H
