//
// Created by 蜗牛 on 2016/11/21.
//

#ifndef COMPOSITE_STATE_H
#define COMPOSITE_STATE_H

#define NORMAL 0;
#define REMOVE 1;


class State {
private:
    int state;
public:
    State() {
        this->state = NORMAL;
    }

    void setState(int state) {
        this->state = state;
    }

    int getState() {
        return state;
    }
};

#endif //COMPOSITE_STATE_H
