//
// Created by zhanGGe on 2018/9/5.
// 快速排序的具体实现 先实现划分函数

int divide(vector<int> a, int low, int high) {
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
}


void quickSort(vector<int> &a, int low, int high){
    if (low == high) return;

    int mid = divide(a, low, high);
    quickSort(a, low, mid -1);
    quickSort(a, mid+ 1, high);
}


