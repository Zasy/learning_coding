//
// Created by 张哲 on 2018/10/16.
//
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int firstMissingPositive(vector<int>& nums) {
    priority_queue<int, vector<int>, greater<int>> q;

    for(auto i : nums){
        if(i > 0) q.push(i);
    }

//    int val = q.top();
//    q.pop();
    int val = 0;

    while(!q.empty()){
        int temp = q.top();
        if(temp == val + 1){
            q.pop();
            val = val + 1;
        }else{
            return val +1;
        }
    }

    return val+1;

}


