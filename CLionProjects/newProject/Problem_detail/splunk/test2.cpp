//
// Created by 张哲 on 2018/10/21.
//

#include <iostream>
#include <vector>


using namespace std;


void dfs(int &count, int &res,  int x, int y, int d_x, int d_y, int M, int N){
    count++;
    for(int i=0; i < 8; i++){
        if(i == 0){
            x = x - 2;
            y = y + 1;
        }else if( i == 1){
            x = x - 1;
            y = y + 2;
        }else if( i == 2){
            x = x + 1;
            y = y + 2;
        }else if( i == 3){
            x = x + 2;
            y = y + 1;
        }else if (i == 4){
            x = x + 2;
            y = y - 1;
        }else if (i == 5){
            x = x + 1;
            y = y - 2;
        }else if (i == 6){
            x = x - 1;
            y = y - 2;
        }else if (i == 7){
            x = x - 2;
            y = y - 1;
        }

        if (x >=0 && x <= M && y >= 0 && y <= N){
            if(x == d_x && d_x == d_y){
                res = 1;
                return;
            }
        }else{
            return;
        }
    }

    for(int i=0; i < 8; i++){
        if(i == 0){
            x = x - 2;
            y = y + 1;
        }else if( i == 1){
            x = x - 1;
            y = y + 2;
        }else if( i == 2){
            x = x + 1;
            y = y + 2;
        }else if( i == 3){
            x = x + 2;
            y = y + 1;
        }else if (i == 4){
            x = x + 2;
            y = y - 1;
        }else if (i == 5){
            x = x + 1;
            y = y - 2;
        }else if (i == 6){
            x = x - 1;
            y = y - 2;
        }else if (i == 7){
            x = x - 2;
            y = y - 1;
        }


        if (x >=0 && x <= M && y >= 0 && y <= N){
            dfs(count, res, x, y, d_x, d_y, M, N);
        }

    }
}


int main(){
    int M, N;
    cin >> M >> N;

    int X, Y;
    cin >> X >> Y;

    int P, Q;
    cin >> P >> Q;


    int count = 0;
    int res = 0;

    dfs(count, res, X, Y, P, Q, M, N);

    if( res == 0){
        cout << -1 << endl;
    }else{
        cout << count << endl;
    };

}

