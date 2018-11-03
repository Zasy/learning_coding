//
// Created by 张哲 on 2018/10/29.
//

#include <initializer_list>
#include <iostream>

double sum(std::initializer_list<double> il);

int main(){
    double total = sum({2,5,1.1,4}); // 4 converted to 4.0

    std::cout << total << std::endl;
}

double sum(std::initializer_list<double> il){
    double tot = 0;
    for(auto p = il.begin(); p != il.end(); p++){
        tot += *p;
    }

    return tot;
}


