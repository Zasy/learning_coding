//
// Created by 张哲 on 2018/11/3.
//


// 懒汉模式
#include <mutex>

class Singleton{
    Singleton(){};
    static Singleton* p;
    static mutex mu;
public:
    Singleton* GetInstance();
};

Singleton::p = nullptr;
Singleton* Singleton::GetInstance() {
    if(p == nullptr){
        mu.lock();
        if(p == nullptr){
            p = new Singleton();
        }
        mu.unlock();
    }
    return p;
}

// 饿汉模式
class Singleton{
    Singleton(){};
    static Singleton* p;
public:
    Singleton* GetInstance();
};


Singleton::p = GetInstance();
Singleton* Singleton::GetInstance() {
    if(p == nullptr){
        p = new Singleton();
        return p;
    }
    return nullptr;
}


