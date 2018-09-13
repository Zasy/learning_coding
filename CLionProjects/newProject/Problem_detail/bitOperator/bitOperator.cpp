//
// Created by zhanGGe on 2018/9/13.
// 位运算 计算数字二进制中1的个数

// 把一个整数减去1之后和原先的数做与操作，相当于把第一个1后面的所有未变成了0

int NumberOf1(int n){
    int count = 0;
    while(n){
        ++count;
        n = (n -1) & n;
    }

    return count;
}
int NumberOf1_2(int n){
    int count = 0;
    unsigned int flag = 1;
    while(flag){
        if(flag & n) count++;
        flag = flag << 1;
    }

    return count;
}

