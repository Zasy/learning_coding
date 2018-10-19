//
// Created by zhanGGe on 2018/10/7.
//


#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5;
const long long INF = 9223372036854775806;

int n,m;
int vis[N];
int pre[N];

long long dis[N];
struct node{
    int u;
    long long w;
};


vector<int> ans;
vector<node> graph[N];
priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> q;

void add(int x, int y , long long z){
    node temp;
    temp.u = y;
    temp.w = z;
    graph[x].push_back(temp);
    temp.u = x;
    graph[y].push_back(temp);
}


void Dijkstra(int x){
    while(!q.empty()){
        pair<long, long, long long> temp;
        temp = q.top();
        q.pop();

        if(vis[temp.second] != 0) continue;
        vis[temp.second]++;
        vector<node>::iterator it;

        for(it = graph[temp.second].begin(); it != graph.[temp.second].end();it++){
            if(vis[it->u] != 0) continue;
            if(dis[it->u] > dis[temp.second] + (it->w)){
                dis[it->u] = dis[temp.second] + (it->w);
                pre[it->u] = temp.second;
                q.push(make_pair(dis[it->u], it->u));
            }
        }
    }
}




