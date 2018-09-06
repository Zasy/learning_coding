//
// Created by zhanGGe on 2018/9/5.
// 题目: 给定一个有序（非降序）数组A，可含有重复元素，求最小的i使得A[i]等于target，不存在则返回-1
// 重点是判断是否为起始位置
// 当起点和终点重合后，直接退出，判断找到的中间位置是否为目标值， 由于start和end相等时会循环不退出，到达相同位置后的判断放到了外部


int search(vector<int> data, int val) {
    int start   = 0;
    int end     = data.size() - 1;

    while(start < end) {
        int mid = start + (end - start) / 2 ;

        if(data[mid] < val) {
            start = mid + 1;
            continue;
        }

        if(data[mid] >= val) {// 如果是大于或等于val 则直接令end 为 mid 不下降
            end  = mid;
            continue;
        }
    }

    if(data[start] == val) {
        return start;
    }else{
        return -1;
    }
}

