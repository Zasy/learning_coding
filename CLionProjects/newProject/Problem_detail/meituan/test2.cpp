//
// Created by 张哲 on 2018/10/22.
//

#include <iostream>
#include <vector>

using namespace std;

int isCover(int l_start, int l_end, int b_start, int b_end){
    if(l_start <= b_start && l_end >= b_end){
        return 1;
    }
    return 0;
}


int main(){
    int N;
    cin >> N;

    vector<int> start(N, 0);
    vector<int> end(N, 0);
    vector<int> record(N, 0);


    for(int i = 0; i < N; i++){
        cin >> start[i] >> end[i];
    }

    for(int i = 1; i <= N ; i++){
        for(int j = i-1; j >= 0; j--){
            if(record[j] == 0){
                if(isCover(start[i], end[i], start[j], end[j])) record[j] = 1;
            }
        }
    }

    int res = 0;

    for(int i = 0; i < N; i++){
        if(record[i] == 1) res++;
    }

    cout << res << endl;
    return 0;
}

