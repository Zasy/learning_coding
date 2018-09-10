//
// Created by 张哲 on 2018/9/9.
//
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<math.h>
#include<map>
using namespace std;

int main(){
    string ori_ip;
    cin >> ori_ip;
    int result = 0;
    for (int a = 1; a <= 3; a++){
        for (int b = 1; b <= 3; b++){
            for (int c = 1; c <= 3; c++){
                for (int d = 1; d <= 3; d++){
                    if (a + b + c + d == ori_ip.length()) {
                        int A = stoi(ori_ip.substr(0, a));
                        int B = stoi(ori_ip.substr(a, b));
                        int C = stoi(ori_ip.substr(a + b, c));
                        int D = stoi(ori_ip.substr(a + b + c, d));
                        if (A <= 255 && B <= 255 && C <= 255 && D <= 255){
                            result++;
                        }
                    }
                }
            }
        }
    }
    cout << result;
}

