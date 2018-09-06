//
// Created by zhanGGe on 2018/9/4.
// 数组中重复的数字 n 个数 范围是0-n-1
// 把所有数放到其原本的地方
#include <iostream>

using namespace std;

bool getDuplicate(vector<int> data, int len) {
    int len = data.length();
    for(int i=0 ; i < len; i++){
        while(data[i] != i) {
            if (data[i] == data[data[i]]){
                cout << data[i] << endl;
                return true;
            }

            int temp = data[data[i]];
            data[data[i]] = data[i];
            data[i] = temp;
        }
    }
}


int main() {
    vector<int> test = {1, 2, 3, 3};

    getDuplicate(test, 4);

    return 0;
}
