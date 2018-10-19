//
// Created by 张哲 on 2018/9/13.
// bfs 类似于树的分层遍历 只有非递归的形式
#include <vector>
#include <deque>
#include <unordered_map>
#include <list>

using namespace std;

//int bfs(vector<vector<int>> graph, int head, vector<int> visited){
//    visited[head] = 1;
//}


class LRU {
public:
    LRU : capacity(int ca){}

    int Get(int key){
        if(pos.find(key) != pos.end()){
            Put(key, recent[pos[key].second]);
            return recent[pos[key]].second;
        }

        return -1;
    }

    int Put(int key, int val){
        if(pos.find(key) != pos.end()){
            recent.erase(pos[key]);
        }else if (pos.size() >= capacity){
            pos.erase(recent.back().first);
            recent.pop_back();
        }

        recent.push_front({key, val});
        pos[key] = recent.begin();
    }

private:
    int capacity;
    list<pair<int, int>> recent;
    unordered_map<int, list< pair<int, int> >::iterator> pos;
};