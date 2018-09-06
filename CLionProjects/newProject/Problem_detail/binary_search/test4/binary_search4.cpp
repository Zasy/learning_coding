//
// Created by zhanGGe on 2018/9/5.
// 一个有序（升序）数组，没有重复元素，在某一个位置发生了旋转后，求target在变化后的数组中出现的位置，不存在则返回-1
// 有序数组发生旋转之后 target的位置
// 通过比较val[start] 和 val[mid] 的关系判断在哪一个区段


int search(vector<int> data, int val) {
    int start   = 0;
    int end     = (int)data.size() - 1;

    while(start <= end) {
        int mid = start + (end - start) / 2;
        if(data[mid] == val) return mid;

        if(data[low] <= data[mid]) {
            // 确定mid所在的位置
            if(val < data[mid] && val >= data[start]) {
                end = mid - 1;
                continue;
            }

            start = mid + 1;
            continue;
        }

        if(val > data[mid] && val <= data[end]) {
            start = mid + 1;
            continue;
        }

        end = mid - 1;
    }

    return -1;
}



