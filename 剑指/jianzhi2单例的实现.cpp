// .h————————————————————————————————————————————————————
class Singleton {
public:
    static Singleton* create();
    ~Singleton(){
        if(p!= nullptr)
            p = nullptr;
    }
private:
    Singleton(){};
    Singleton(const Singleton&){};
    static Singleton *p;
};
void jianzhi2();

// .cpp———————————————————————————————————————————————————
// Created by 陈某林 on 2022/6/22.
//
#include "jianzhi2.h"
#include <iostream>
Singleton* Singleton::p = nullptr;
Singleton* Singleton::create() {
    if(p == nullptr){
        p = new Singleton;
        std::cout<<"new----"<<p<<std::endl;
    }
    return p;
}
void jianzhi2() {
    Singleton *p1 = Singleton::create();
    std::cout<<p1<<std::endl;
    Singleton *p2 = Singleton::create();
    std::cout<<p2<<std::endl;
    delete p1;
    Singleton *p3 = Singleton::create();
    std::cout<<p3<<std::endl;
}
