#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


int main(){
    int N;
    cin >> N;

    vector<int> data(N, 0);

    for(int i= 0 ; i < N; i++){
        cin >> data[i];
    }

    vector<int> idx1(N, 0);
    vector<int> idx2(N, 0);

    idx1[0] = data[0];
    idx2[0] = 0;
    cout << data[0] << endl;
    for(int i = 1; i < N; i++){
        vector<int> temp(3, 0);
        temp[0] = idx1[i - 1];
        temp[1] = idx2[i - 1];
        temp[2] = data[i];
        cout << idx1[i-1] << " " << idx2[i-1] << " " <<data[i] << endl;
        sort(temp.begin(), temp.end());
        cout << temp[0] << " " << temp[1] << " " <<temp[2] << endl;

        idx1[i] = temp[2];
        idx2[i] = temp[0] + temp[1];
    }

    cout << max(idx1[N-1], idx2[N-1]) << endl;

    return 1;

}

