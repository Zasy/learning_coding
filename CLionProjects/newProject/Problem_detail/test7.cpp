#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<math.h>
#include<map>
using namespace std;

int main(){
    int m, n;
    cin >> m >> n;
    vector<vector<int>>matrix(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }

    int k;
    cin >> k;
    bool result= false;

    int row = 0;
    int column = n - 1;

    while(row < m && column >= 0){
        if(matrix[row][column] == k){
            result = true;
            break;
        }
        else if(matrix[row][column] > k){
            --column;
        }

        ++row;
    }
    if(result) {
        cout << "true" << endl;
    }else{
        cout << "false" << endl;
    }


    return 1;
}

