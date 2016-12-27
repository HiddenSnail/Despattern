//
// Created by 蜗牛 on 2016/12/6.
//

#ifndef UNDOREDO_SINGLETON_H
#define UNDOREDO_SINGLETON_H

#include <string>

template <class T>
class Singleton {
private:
    Singleton() {}
    Singleton(const Singleton& rhs);
    Singleton& operator=(const Singleton& rhs);
    static T* pt;
public:
    static T* instance() {
        if(NULL == pt) {
            pt = new T();
        }
        return pt;
    }
};

template <class T>
T* Singleton<T>::pt = NULL;
#endif //UNDOREDO_SINGLETON_H
