//
// Created by 张哲 on 2018/11/8.
//

#include <vector>
#include <iostream>

using namespace std;

vector<int> MySort(vector<int> data){
    int len = data.size();
    int i = 0;
    int j = (len % 2 == 0) ? len -1 : len - 2;

    vector<int> res(len, 0);

    while( i <= len - 1 && j >= 0){
        if(data[i] < data[j]){
            res.push_back(data[i]);
            i = i + 2;
        }else{
            res.push_back(data[j]);
            j = j - 2;
        }
    }

    while(i <= len - 1){
        res.push_back(data[i]);
        i = i+ 2;
    }

    while(j >= 0){
        res.push_back(data[j]);
    }

    return res;

}

int main(){
    vector<int> data = {10, 1, 9, 2, 5, 3};

    for(auto v : MySort(data)){
        cout << v << " " ;
    }
    cout << endl;
    return 1;
}

