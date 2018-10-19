//
// Created by zhanGGe on 2018/9/21.
//


#include <iostream>
#include <vector>
#include <string>

using namespace std;

void backtrack(int now, vecotr<string> &res, int & data, string now_res){
    if(now == data){
        res.push_back(now_res);
        return;
    }

    if(now > data) return;

    backtrack(now*2 + 1, res, data, now_res + '2');
    backtrack(now*2 + 2, res, data, now_res + '3');
}

int main(){
    int data;
    cin >> data;
    vector<string> res;
    vector<int> times(1000, 0);
    string now_res = "";
    backtrack(0, res, data, now_res);

    int min_index = 0;
    for(int i = 0; i < res.size(); i++){
        if(res[i].size() <res[min_index].size()){
            min_index = i;
        }
    }

    cout << res[min_index] << endl;

    return 0;
}