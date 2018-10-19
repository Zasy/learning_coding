//
// Created by zhanGGe on 2018/9/20.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;



int main(){
    string temp;
    vector<string> input;
    cin >> temp;
    while(temp != "END"){
        input.push_back(temp);
        cin >> temp;
    }

    vector<int> res;
    vector<int> record(100000, 0);

    int len = input.size();
    for(int i = 0; i< len; i++){
        int jinzhi = 0;
        int j = 0;
        for( ; j < input[i].size(); j++){
            if(input[i][j] != '#'){
                jinzhi = jinzhi*10 + input[i][j] - '0';
                continue;
            }
            break;
        }

        int number = 0;
        for(int n = j+1; n < input[i].size(); n++){
            number = number*jinzhi + input[i][j] - '0';
        }
        record[number]++;
        res.push_back(number);
    }

    for(int i=0; i < len; i++){
        if(record[res[i]] == 1) {
            cout << input[i] << endl;
        }
    }



    return 0;
}

