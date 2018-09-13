//
// Created by zhanGGe on 2018/9/13.
//


int atoi(string str){
    int     sign = 1, i = 0;
    long    base = 0;
    // 去除字符串开始前的空格
    while(str[i] == ' ') i++;
    // 判断数字开始前是否有输入正负号
    if(str[i] == '-') {
        sigh = -1;
        i++;
    }else if(str[i] == '+'){
        i++;
    }
    // 对所有的数字运算
    while(str[i] >= '0' && str[i] <= '9'){
        // 对输入的string转化为int表示范围的限制
        base = base*10 + str[i++] - '0';
        if(base*sign >= INT_MAX) return INT_MAX;
        if(base*sign <= INT_MIN) return INT_MIN;
    }

    return base*sign;
}

