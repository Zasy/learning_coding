//
// Created by zhanGGe on 2018/9/12.
// 打印斐布拉奇数列


// 非递归

int fibonacci(int n) {
    if (n == 0) return 0;
    if(n == 1) return 1;

    return fibonacci(n-1) + fibonacci(n-2);
}

// 递归

int fibonacci(int n){
    if (n == 0) return 0;
    if(n == 1) return 1;
    int a = 0;
    int b = 1;

    for(int i=2; i <= n; i++){
        a = a + b;
        int temp = a + b;
        a = b;
        b = temp;
    }

    return b;
}