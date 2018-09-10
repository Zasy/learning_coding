//
// Created by 张哲 on 2018/9/9.
//


#include <iostream>
#include <vector>


using namespace std;



string ConvertToString(int num){
    string res;
    int d = 2;
    for(int i=0; i < 8; i++){
        int temp = num % 2;
        num = num / 2;

        if (temp == 1) res = '1' + res;
        else{
            res = '0' + res;
        }
    }

    return res;

}

int main(){
    int N;
    cin >> N;

    vector<int> input(N, 0);
    vector<string> utf(N);

    for(int i =0; i < N; i++){
        cin >> input[i];
        utf[i] = ConvertToString(input[i]);
    }

    if(N == 1) {
        if (utf[0][0] == '0') {
            cout << 1 << endl;
        }
    }
//    }else{
//        string substr = utf[0].substr(0, N+1);
//        if(N == 2){
//            if(substr == "110" && utf[1].substr(0, 2) == "10"){
//                cout << 1 << endl;
//                return 1;
//            }
//        }
//
//        if(N == 3){
//            if(substr == "1110" && utf[1].substr(0, 2) == "10" && utf[2].substr(0, 2) == "10"){
//                cout << 1 << endl;
//                return 1;
//            }
//        }
//
//        if(N == 4){
//            if(substr == "11110" && utf[1].substr(0, 2) == "10" && utf[2].substr(0, 2) == "10" && utf[3].substr(0, 2) == "10"){
//                cout << 1 << endl;
//                return 1;
//            }
//        }
//    }
    cout << 0 << endl;
    return 0;
}
