#include <vector>
#include <deque>          // std::deque
#include <list>           // std::list
#include <queue>          // std::queue
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

struct Data {
    int age;
    string name;
};

int main() {
    int N,M;
    cin >> N >> M;
    vector<Data> test;
    for(int i = 0; i < N ; i++){
        Data test_temp;
        cin >> test_temp.age >> test_temp.name;
        test.push_back(test_temp);
    }

    for(int i = 0; i < N; i++) {
        cout << test[i].age << test[i].name << endl;
    }
}

