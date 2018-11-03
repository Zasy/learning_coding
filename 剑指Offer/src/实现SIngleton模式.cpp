//
// Created by 张哲 on 2018/11/3.
//

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