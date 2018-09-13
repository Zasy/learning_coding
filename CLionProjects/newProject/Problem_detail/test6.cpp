// 二分图
//


#include <queue>
#include <iostream>
#include <vector>

using namespace std;


bool bfs(int s, int n, vector<int> & color, vector<vector<int>> & graph){
    queue<int> q;
    q.push(s);

    color[s] = 1;
    while(!q.empty()){
        int from = q.front();
        q.pop();
        for(int i=1; i<= n; i++){
            if(graph[from][i] && color[i] == -1){
                q.push(i);
                color[i] = !color[from];
            }

            if(graph[from][i] && color[from] == color[i]){
                return false;
            }
        }
    }

    return true;
}


int main() {
    int N, M;
    cin >> N >> M;
    vector<int> color(N+1, -1);
    vector<vector<int>> graph(N+1, vector<int>(N+1, 0));

    for(int i=0; i < M; i++){
        int a,b;
        cin >> a >> b;
        graph[a][b] = graph[b][a] = 1;
    }

    bool flag = false;

    for(int i = 1; i<=N; i++){
        if(color[i] == -1 && !bfs(i,N, color, graph)){
            flag = true;
            break;
        }
    }

    if(flag) cout << "No" << endl;
    else{
        cout << "Yes" << endl;
    }

    return 0;
}

