//
// Created by 张哲 on 2018/10/22.
//

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> sig(n ,0);

    for(int i = 0; i < n; i++){
        cin >> sig[i];
    }

    vector<int> rec(n, 0);

    for(int i=0; i < n; i++){
        int start = i - sig[i];
        int end = i + sig[i];

        for(int j = start; j <= end; j++){
            if(j != i && j>= 0 && j < n){
                rec[j]++;
            }
        }
    }
    int res = 0;
    for(int i=0; i < n; i++){
        if(rec[i] >= k) res++;
    }

    cout << res;


    return 0;
}