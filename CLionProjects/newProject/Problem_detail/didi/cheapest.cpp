#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;


/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^
******************************开始写代码******************************/
int find_cheapest_path(int n, int m, vector < vector < int > > flights) {
    vector<vector<int>> g(n , vector<int>(n, -1));

    for(auto flight : flights){
        g[flight[0]][flight[1]] = 1;
    }

    for



}
/******************************结束写代码******************************/


int main() {
    int res;

    int _n;
    cin >> _n;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');


    int _m;
    cin >> _m;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');


    int _flights_rows = 0;
    int _flights_cols = 0;
    cin >> _flights_rows >> _flights_cols;
    vector< vector < int > > _flights(_flights_rows);
    for(int _flights_i=0; _flights_i<_flights_rows; _flights_i++) {
        for(int _flights_j=0; _flights_j<_flights_cols; _flights_j++) {
            int _flights_tmp;
            cin >> _flights_tmp;
            _flights[_flights_i].push_back(_flights_tmp);
        }
    }

    res = find_cheapest_path(_n, _m, _flights);
    cout << res << endl;

    return 0;

}
