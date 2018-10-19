//
// Created by 张哲 on 2018/9/15.
//

#include <vector>
#include <iostream>
#include <string>
using namespace std;

int main(){
    int N, M, P;
    cin >> N >> M >> P;
    vector<int> A(N, 0);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    for(int i = 0 ; i < M; i++){
        string leixing;
        int  temp;
        cin >> leixing >> temp;
        if (leixing == "A") {
            A[temp]++;
        }else{
            A[temp]--;
        }
    }
    int val = A[P];
    int count = 0;
    for(int i=0; i < N; i++){
        if(A[i] > val){
            count++;
        }
    }
    cout << count + 1 << endl;
    return 0;
}




