//
// Created by zhanGGe on 2018/9/4.
// 实现单例模型

class singleton {
protected:
    singleton(){};
private:
    static singleton* p;
public:
    static singleton* instance();
};


int main

