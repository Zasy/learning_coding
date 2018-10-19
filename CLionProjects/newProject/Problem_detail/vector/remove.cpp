//
// Created by 张哲 on 2018/10/17.
//

#include <vector>
#include <iostream>
#include <map>

using namespace std;

int main(){
    vector<int> c{0, 1, 2, 3, 4, 5, 6, 7};

    for(auto &i : c) {
        cout << i << " " ;
    }
    cout << "\n";

    c.erase(c.begin());

    for(auto &i : c) {
        cout << i << " ";
    }
    cout << "\n";

    c.erase(c.begin() + 2, c.begin() + 5);

    for (auto &i : c) {
        cout << i << " ";
    }
    cout << "\n";

    for (auto i = c.begin();  i != c.end() ; ) {
        if(*i % 2 == 0){
            i = c.erase(i);
        }else{
            ++i;
        }
    }

    for(auto &i : c){
        cout << i << " ";
    }
    cout << "\n";



    map<int, std::string> c_map = {{1, "one"}, {2, "two"}, {3, "three"},
                                    {4, "four"}, {5, "five"}, {6, "six"}};
    // erase all odd numbers from c
    for(auto it = c_map.begin(); it != c_map.end(); )
        if(it->first % 2 == 1)
            it = c_map.erase(it);
        else
            ++it;
    for(auto& p : c_map)
        cout << p.second << ' ';
}