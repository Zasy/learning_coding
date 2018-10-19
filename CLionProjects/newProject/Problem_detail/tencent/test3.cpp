//
// Created by zhanGGe on 2018/9/16.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    long X, Y, Z;

    cin >> X >> Y >> Z;

    vector<long> sums;
    val[0] = X;
    val[1] = Y;
    val[2] = Z;

    for(int i=1; i <= X; i++){
        sums.push_back(i);
    }

    for(int i=1; i <= Y; i++){
        sums.push_back(i);
    }

    for(int i=1; i<= Z; i++){
        sums.push_back(i);
    }

    sort(snums.begin(), snums.end());
    int count = 0;
    for ( int n = nums.size(), k = n - 1; k > 1; --k ) {
        int i = 0, j = k - 1;
        while ( i < j ) {
            // any value x between i...j will satisfy snums[x] + snums[j] > snums[k]
            // and because snums[k] > snums[j] > snums[x] >= 0, they will always satisfy
            // snums[k] + snums[x] > snums[j] and snums[k] + snums[j] > snums[x]
            if ( snums[i] + snums[j] > snums[k] )
                count += --j - i + 1;
            else
                ++i;
        }
    }
    cout << count << endl;
    return 1;
}

