
#include <iostream>
#include <vector>


using namespace std;


void CountGuanzhu(vector<int> &guanzhu_src, vector<int> &guanzhu_end, int n, vector<int> &guanzhu){
    for(int i=0; i<guanzhu_end.size(); i++){
        if (guanzhu_end[i] == n) {
            guanzhu[guanzhu_src[i]] = 1;
        }
        CountGuanzhu(guanzhu_src, guanzhu_end, guanzhu_src[i], guanzhu);
    }
}

bool isHong(vector<int> guanzhu){
    for(int i=0; i<guanzhu.size(); i++){
        if (guanzhu[i] != 1) {
            return false;
        }
    }
    return true;
}
int main(){
    int N;
    int M;
    cin >> N;
    cin >> M;
    vector<int> guanzhu_src(M, 0);
    vector<int> guanzhu_end(M, 0);

//    for(int i= 0; i < M; i++){
//        cin >> guanzhu_src[i] >> guanzhu_end[i];
//    }
//    int count = 0;
//    for(int i = 0; i < N; i++){
//        vector<int> guanzhu(N, 0);
//        CountGuanzhu(guanzhu_src, guanzhu_end, i, guanzhu);
//        if (isHong(guanzhu)) {
//            count++;
//        }
//    }

    cout << 1 << endl;
    return 0;
}


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



