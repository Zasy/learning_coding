//
// Created by zhanGGe on 2018/10/7.
//


#include <vector>
#include <queue>
#include "limits.h"

using namespace std;

// M nodes
// N edges
// 双向图


int Dijkstra(int x){
    while(!q.empty()){
        pair<int, int> temp;
        temp = q.top();
        q.pop();

        if( vis[temp->second] != 0) continue;
        vis[temp->second]++;

        for(int i = 1; i <= M; i++){
            if(graph[temp->second][i] < INT_MAX && vis[i] != 0 && dis[i] > dis[temp->second] + graph[temp->second][i]){
                dis[i] = dis[temp->second] + graph[temp->second][i];
                pre[i] = temp->second;
                q.push_back(make_pair(dis[i], i));
            }
        }
     }
}


int main(){
    int M,N;
    cin >> M >> N;

    vector<vector<int>> graph(M+1, vector<int>(M+1, -1));

    for(int i =0; i < N; i++){
        int s, e , v;
        cin >> s >> e >> v;
        graph[s][e] = v;
    }

    vector<int> dis(M+1, INT_MAX);
    vector<int> pre(M+1, 0);
    vector<int> vis(M+1, 0);
    dis[1] = 0;

    priority_queue< pair<int, int>, vector< pair<int, int>>, greater< pair<int, int> >> q;
    q.push(make_pair(dis[1], 1));
}
