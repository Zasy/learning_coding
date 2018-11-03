//
// Created by 张哲 on 2018/10/21.
//

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

const int maxLength = 10;

char* comb1 = new char[maxLength*2 + 1];
char* comb2 = new char[maxLength*2 + 1];

int compare(const void *strNumber1, const void* strNumber2){
    strcpy(comb1, *(const char**)strNumber1);
    strcat(comb1, *(const char**)strNumber2);

    strcpy(comb2, *(const char**)strNumber2);
    strcat(comb2, *(const char**)strNumber1);

    return strcmp(comb1, comb2);
}


void GetMinNumber(int *numbers, int length){
    if(numbers == nullptr || length <= 0){
        return;
    }

    char** strNumbers = (char**)(new int[length]);
    for(int i = 0; i < length; ++i){
        strNumbers[i] = new char[maxLength + 1];
        sprintf(strNumbers[i], "%d", numbers[i]);
    }

    qsort(strNumbers, length, sizeof(char*), compare);

    for(int i = 0; i < length; i++){
        printf("%s", strNumbers[i]);
    }
    printf("\n");


    for(int i = 0; i < length; i++){
        delete[] strNumbers[i];
    }
    delete[] strNumbers;
}

int main(){
    int N;
    int numbers[100];
    cin >> N;
    for(int i = 0 ; i < N; i++){
        cin >> numbers[i];
    }

    GetMinNumber(numbers, N);

    return 0;
}

