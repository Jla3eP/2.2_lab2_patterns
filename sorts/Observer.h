//
// Created by vikid on 01.05.2021.
//

#ifndef INC_2_2_LAB2_PATTERNS_LAST_OBSERVER_H
#define INC_2_2_LAB2_PATTERNS_LAST_OBSERVER_H


class Observer {
public:
     virtual void update(int * array, int size) = 0;
};

class ObserverPrint : public Observer {
public:
    virtual void update(int * array, int size);
};


#endif //INC_2_2_LAB2_PATTERNS_LAST_OBSERVER_H
