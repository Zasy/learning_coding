//
// Created by zhanGGe on 2018/9/16.
//


#include <iostream>
#include <vector>

using namespace std;

long long getAll(long long total){
    long i = 1;
    long long val = (i+1)*i/2;
    while( val < total){
        i = i + 1;
        val = (i+1)*i/2;
    }

    if(val == total) return i;

    return -1;
}

int main(){
    long long X, Y;
    cin >> X >> Y;

    long long total = X + Y;

    long long n = getAll(total);
    if (n == -1) {
        cout << -1 << endl;
        return -1;
    }

    long long i = 1;
    long long val = 1;
    while( i <= n){
         val = val  + (n - i + 1);
         if (X <= val){
             cout << i << endl;
             return 0;
         }
         i++;
    }
    cout << -1 << endl;
    return -1;
}

