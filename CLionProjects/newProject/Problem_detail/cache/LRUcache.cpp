//
// Created by zhanGGe on 2018/9/6.
//
#include <unordered_map>

using namespace std;

class LRUCache {
public:
    LRUCache : capacity(int capacity){}

    int Get(int key) {
        if (pos.find(key) != pos.end()) {
            Put(key, recent[pos[key]].second);
            return recent[pos[key]].second;
        }

        return -1;
    }

    int Put(int key, int value) {
        if (pos.find(key) != pos.end()) {
            recent.erase(pos[key]);
        }else if(pos.size() >= capacity) {
            pos.erase(recent.back().first);
            recent.pop_back();
        }
        recent.push_front({key, value});
        pos[key] = recent.begin();
    }

private:
    int capacity;
    list<pair<int, int>> recent;
    unordered_map<int, list<pair<int, int>>::iterator> pos; // 存储一个迭代器
};

