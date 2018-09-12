//
// Created by 张哲 on 2018/9/13.
// DFS的递归举例

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<math.h>
#include<map>
using namespace std;

int dfs(vector<vector<int>>follow, int person,int &tmp,vector<bool>&visit){
    for (int i = 0; i < follow.size(); i++){
        if (follow[i][person] == 1 && visit[i] == false){
            tmp++;
            visit[i] = true;
            dfs(follow, i, tmp, visit);
        }
    }

    return tmp;
}

bool isHong(vector<bool> visit) {
    for(int i=0 ; i< visit.size(); i++){
        if (visit[i] == false){
            return false;
        }
    }
    return true;
}

int main(){
    int N, M;
    cin >> N >> M;
    int result = 0;
    vector<vector<int>>follow(N,vector<int>(N,0));
    for (int i = 0; i < M; i++){
        //follow[i][i] = 1;
        int m, n;
        cin >> m >> n;
        follow[m-1][n-1] = 1;
    }

    for (int i = 0; i < N; i++){
        int tmp = 0;
        vector<bool>visit(N, false);
        visit[i] = true;
        int wanghong=dfs(follow, i, tmp, visit);

        if (isHong(visit)) result++;

    }
    cout << result;
}





