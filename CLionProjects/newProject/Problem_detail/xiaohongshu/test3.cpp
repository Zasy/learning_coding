//
// Created by zhanGGe on 2018/9/18.
//
#include <iostream>
#include <vector>
#include <string>
#include<cstring>
#include<cstdio>

using namespace std;


int PowerBase10(unsigned int n){
    int result = 1;
    for(unsigned int i =0; i < n; i++) result*=10;

    return result;
}

int Numberof1(const char* number){
    int first = *number - '0';
    unsigned int len = static_cast<unsigned int>(strlen(number));

    if(len == 1 && first == 0){
        return 0;
    }

    if(len == 1 && first > 0){
        return 1;
    }

    int numFirstDigit = 0;
    if(first > 1){
        numFirstDigit = PowerBase10(len - 1);
    }else if(first == 1){
        numFirstDigit = atoi(number + 1) + 1;
    }

    int numOtherDigits = first*(len - 1)*PowerBase10(len - 2);

    int numRecursive = Numberof1(number + 1);

    return numFirstDigit + numOtherDigits + numRecursive;
}


int main(){
//    string number;
//    cin >> number;
//
//
    char str[30];
    scanf("%s", str);
    int count = Numberof1(str);
    cout << count << endl;

    return 0;

}

