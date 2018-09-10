//
// Created by 张哲 on 2018/9/9.
//



#include <vector>
#include <iostream>

using namespace std;

int main(){
    int M;
    cin  >> M;

    vector<vector<int>> m(M, vector<int>(M, 0));


    for(int i=0; i < M; i++){
        for(int j=0; j < M; j++){
            cin >> m[i][j];
        }
    }

    vector<int> count(M, 0);

    if(m[0][0] == 1){
        count[0] = 1;
    }

    for(int i=1; i < M; i++){
        if(m[0][i] == 1 && m[0][i-1] != 1) count[0]++;
    }

    for(int i=1; i < M; i++){
        if(m[i][0] == 1 && m[i-1][0] != 1) count[i] = 1;
    }

    for(int i=1; i < M; i++){
        for(int j=1; j < M; j++){
            if(m[i][j] == 1 && m[i-1][j] != 1 && m[i][j -1] != 1) count[i]++;
        }
    }

    int all = 0;
    for(int i=0 ; i< M; i++){
        all = all + count[i];
    }

    cout << all;
}