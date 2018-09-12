//
// Created by 张哲 on 2018/9/13.
// 非递归的DFS应用 遍历所有点 可以使用stack
#include <vector>
#include <stack>
using namespace std;

void DFS(vector<vector<int>> G,int vo, vector<int> visited) {
    int v, w;
    stack<int> s;
    s.push(vo);

    while (!s.empty()) {
        //pop(s, &v);
        v = s.top();
        s.pop();
        if (!visited[v]) {
            //visit(G, v);
            visited[v] = 1;
        }
        w = FirstAdjvertex(G, v);
        while (w != -1) {
            if (!visited[w])
                push(s, w);
            w = NextAdjVertex(G, v, w);
        }

    }
}
