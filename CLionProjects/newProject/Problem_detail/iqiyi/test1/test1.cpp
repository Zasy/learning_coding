//
// Created by 张哲 on 2018/9/15.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int getResult(vector<int> k , int cha){
    int res = 0;
    for(int i = 0; i < k.size(); i++){
        if(k[i] >= cha){
            return i+1;
        }
        cha = cha - k[i];
    }

    return res;
}

int main(){
    string N;
    cin >> N;

    int bef = 0;
    int lst = 0;

    for(int i = 0; i < 3; i++){
        bef += (N[i] - '0');
        lst += (N[i+3] - '0');
    }

    vector<int> k(3, 0);
    if (bef == lst) {
        cout << 0 << endl;
        return 0;
    }

    if(bef > lst){
        for(int i=0; i < 3; i++){
            k[i] = 9 - (N[i+3] - '0');
        }
        sort(k.begin(), k.end(), greater<int>());

        cout << getResult(k, (bef - lst)) << endl;
        return 0;
    }

    for(int i=0; i < 3; i++){
        k[i] = 9 - (N[i] - '0');
    }
    sort(k.begin(), k.end(), greater<int>());

    cout << getResult(k, (lst - bef)) << endl;
    return 0;
}
