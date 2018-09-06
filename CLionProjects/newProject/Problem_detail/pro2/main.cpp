//
// Created by zhanGGe on 2018/9/4.
// 实现C++的单例模型, 及其深度的理解，转化为博文
// 单例模式的定义： 该类只能生成一个实例的对象 一个实例对象
// 必要性： 每次都去new一个对象，即增加了开销，也使得代码更加臃肿，大多数的
// 类为工具性的， 基本不用存储太多的跟自身有关的数据。
// 对比其他方法： 全局或者静态变量的方式，会影响封装性，难以保证别的代码不会对全局变量造成影响

// 普通单例模式
// 不支持多线程，不是严格意义上的单例模型
// 多线程环境在检查是否为null时，多线程会重复的生成多个实例
class singleton {
protected:
    singleton(){};
private:
    static singleton* p = nullptr;
public:
    static singleton* instance();
    void showMessage(){
        cout << "test singleton" << endl;
    }
};

singleton* singleton::p = nullptr;
singleton* singleton::instance() {
    if (p == nullptr) p = new singleton();
    return p;
}

// 懒汉模式 防止多线程时生成多个实例, 用加锁的方法
// 采用加锁的方法有一个问题会影响性能
class singleton
{
protected:
    singleton()
    {
        pthread_mutex_init(&mutex);
    }
private:
    static singleton* p;
public:
    // 给类配了一把互斥锁
    static pthread_mutex_t mutex;
    static singleton* initance();
};

pthread_mutex_t singleton::mutex;
singleton* singleton::p = NULL;
singleton* singleton::initance()
{
    if (p == NULL)
    {
        // 生成实例前先加锁 ,防止其他线程生成实例
        pthread_mutex_lock(&mutex);
        if (p == NULL)
            p = new singleton();
        // 生成实例后再释放锁，这样其他线程来常检查指针时已经存在锁了
        pthread_mutex_unlock(&mutex);
    }
    return p;
}

// 饿汉模式的单例模型 在定义时直接生成分配单例的空间

class singleton
{
protected:
    singleton()
    {}
private:
    static singleton* p;
public:
    static singleton* initance();
};
singleton* singleton::p = new singleton;
singleton* singleton::initance()
{
    return p;
}


