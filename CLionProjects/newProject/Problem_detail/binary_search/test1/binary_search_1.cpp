//
// Created by zhanGGe on 2018/9/5.
// 最基础 对有序序列做二分，找到对应的元素， 非递归和递归思路要清晰

// 非递归的方法 通过start 和 end 决定当前的状态
int search(vector<int> data, int val) {

    int start   = 0;
    int end     = (int)data.size() - 1;

    while(start <= end) {
        int mid = start + (end - start) /2;
        cout << "mid: " << mid << endl;
        if (data[mid] == val) {
            return mid;
        }

        if (data[mid] > val) {
            end = mid - 1;
            continue;
        }

        if (data[mid] < val) {
            start = mid + 1;
            continue;
        }
    }

    return -1;
}

// 递归方法

int search(vector<int> data, int start, int end, int val) {
    //递归结束条件
    if(start <= end) {
        int mid = start + (end - start) / 2;
        if(data[mid] == val) {
            return mid;
        }
        if(data[mid] < val) {
            return search(data, mid+1, end, val);
        }

        return search(data, start, mid-1, val);

    }

    return -1;
}



