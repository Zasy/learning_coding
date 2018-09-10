//
// Created by 张哲 on 2018/9/9.
//


#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    string str;
    cin >> str;

    int len =(int)str.length();
    vector<int> pos(26, -1);

    int cur = 0;
    int max = 0;
    for (int i = 0; i < len; ++i) {
        int pre = pos[str[i] - 'a'];
        if(pre < 0 || i - pre > cur) ++cur;
        else{
            if(cur > max){
                max = cur;
            }
            cur = i - pre;
        }

        pos[str[i] - 'a'] = i;
    }

    if(cur > max) max = cur;

    cout << max << endl;

    return 0;
}
