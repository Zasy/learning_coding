//
// Created by 张哲 on 2018/11/13.
//


#include <vector>
#include <iostream>

using namespace std;


void merge(vector<int> &data, int left, int mid, int right){
    vector<int> r_data(mid - left, 0);
    for(int i = 0; i < mid - left; i++){
        r_data[i] = data[left + i];
    }

    int i = 0;
    int j = mid + 1;
    int n = 0;
    while( i < mid - left && j <= right){
        if(r_data[i] < data[j]){
            data[n] = r_data[i];
            i++;
        }else{
            data[n] = data[j];
            j++;
        }
        n++;
    }

    while( i < mid - left){
        data[n] = r_data[i];
        n++;
        i++;
    }

    while(j <= right){
        data[n] = data[j];
        j++;
        n++;
    }
}

void mergeSort(vector<int> &data, int left, int right){
    if(start >= right) return;

    int mid = left + (right - left) / 2;
    mergeSort(data, left, mid);
    mergeSort(data, mid+1, right);

    merge(data, left, mid, right);
}
