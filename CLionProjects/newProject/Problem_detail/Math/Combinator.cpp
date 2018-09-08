//
// Creat ed by 张哲 on 2018/9/7.
// add the combinator and factory funciton of math

long factorial(long data){
    if (data == 0) return 1;

    return data * factorial(data - 1);
}


// computation the combinator of Cm_{n} 组合数公式
long combinator(long n, long m){
    return factorial(n) / (factorial(n- m) * (factorial(m))) ;
}

// 排列数 Am_{n}

long premutation(long n, long m){
    return factorial(n) / factorial(m);
}


