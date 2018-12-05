//
// Created by 张哲 on 2018/11/13.
//

#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> & data, int left, int right){
    int k = data[left];

    while(left < right){
        while(left < right && data[right] >= k) right--;
        if(left < right) {
            data[left] = data[right];
            left++;
        }
        while(left < right && data[left] <= k) left++;
        if(left < right){
            data[right] = data[left];
            right--;
        }
    }

    data[left] = k;
    return left;
}


int quickSort(vector<int> &data, int left, int right){
    int mid = partition(data, left, right);
    if(left < mid - 1){
        quickSort(data, left, mid - 1);
    }
    if(mid + 1 < right){
        quickSort(data, mid + 1, right);
    }
}

int main(){
    vector<int> data = {2,42,434,312, 42, 2,4};

    quickSort(data, 0, data.size() - 1);

    for(auto d : data){
        cout << d << " ";
    }
    cout << endl;
}

