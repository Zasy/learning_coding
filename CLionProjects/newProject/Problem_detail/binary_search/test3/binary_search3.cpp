//
// Created by zhanGGe on 2018/9/5.
// 给定一个有序（非降序）数组A和一个有序（非降序）数组B，可含有重复元素，求两个数组合并结果中的第k(k>=0)个数字。
// 由于原序列是带顺序的， 这样每次比较的大小后 可以删除掉一定的数量 定好退出条件后就可以找到对应的数字

// 这个可以用来解决中位数的问题 找到中间2位的数字后取平均数， 或者奇偶考虑

int getKthSmallest(vector<int> num1, int s1, int l1, vector<int> num2, int s2, int l2, int k) {
    if (l1 > l2) return getKthSmallest(num2, s2, l2, num1, s1, l1, k);
    if (l1 == 0) return num2[s2 + k - 1];
    if (k == 1) return min(num1[0], num2[0]);

    int i = min(l1, k/2), j = min(l2, k/2);
    if(num1[s1 + i - 1]  < num2[s2 + j - 1]) return getKthSmallest(num1, s1+i, l1- i, num2, s2, l2, k - i);

    return getKthSmallest(num1, s1, l1, num2, s2+j, l2-j, k - j);
}


