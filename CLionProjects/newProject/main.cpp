//
// Created by zhanGGe on 2018/9/4.
// 数组中重复的数字 n 个数 范围是0-n-1
// 把所有数放到其原本的地方
#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

int divide(vector<int> &a, int low, int high) {
    int k = a[low];

    while(low != high) {
        while(low < high && a[high] > k) high--;
        if(low < high) {
            a[low] = a[high];
            low++;
        }
        while(low < high && a[low] < k) low++;
        if(low < high) {
            a[high] = a[low];
            high--;
        }
    }
    a[low] = k;

    return low;
}

int main() {
    time_t start ,end ;
    double cost;

    vector<int> test = {3, 8, 9, 1, 2, 4};

    vector<int> test2 = {2, 3, 4, 4, 5, 6};
    time(&start);
    int result = divide(test, 0, 5);
    time(&end);

    for(int i = 0; i < test.size(); i++) cout << test[i] << endl;

    cost=difftime(end,start);
    cout << "result: " << result << endl;
    cout << "cost: " << cost << endl;
    return 0;
}