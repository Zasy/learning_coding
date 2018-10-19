#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string input;
    cin >> input;
    string res = "";


    int len = input.size();

    int p = 0;
    for(int i=1; i < len; i++){
        if(input[i] != input[i - 1]){
            if (i - p > 1){
                res = res + to_string(i - p) + input[p];
            }else{
                res = res + input[p];
            }
            p = i;
        }
    }
    if (len - p > 1){
        res = res + to_string(len - p) + input[p];
    }else{
        res = res + input[p];
    }

    cout << res << endl;

    return 0;

}