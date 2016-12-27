//
// Created by 蜗牛 on 2016/12/6.
//

#ifndef UNDOREDO_FACTORY_H
#define UNDOREDO_FACTORY_H

#include <vector>
#include <string>
#include "Singleton.h"
#include <map>

template <class AbstractProduct, class IndentifierType, typename ProductCreator = AbstractProduct* (*)()>
class Factory {
    friend class Singleton<Factory<AbstractProduct, IndentifierType, ProductCreator>>;
private:
    std::map<IndentifierType, ProductCreator> associations;

    Factory() {}
    Factory(Factory& factory);
    Factory& operator=(const Factory& factory);
public:
    static Factory* instance(){
        return Singleton<Factory<AbstractProduct, IndentifierType, ProductCreator>>::instance();
    }

    void registerProduct(const IndentifierType& id, ProductCreator creator) {
        associations[id] = creator;
    }

    bool unRegisterProduct(const IndentifierType& id) {
        return 1 == associations.erase(id);
    }

    AbstractProduct* createObject(const IndentifierType& id) {
        typename std::map<IndentifierType, ProductCreator>::iterator it = associations.find(id);
        if (it != associations.end()) {
            return (it->second)();
        }
        return NULL;
    }

    std::vector<IndentifierType> keys() {
        std::vector<IndentifierType> result;
        typename std::map<IndentifierType, ProductCreator>::iterator it = associations.begin();
        for (;it != associations.end();it++) {
            result.push_back(it->first);
        }
        return result;
    }

};

#endif //UNDOREDO_FACTORY_H
