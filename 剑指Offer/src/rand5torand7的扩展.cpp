//
// Created by 张哲 on 2018/11/8.
//

int rand7(){

    int res;
    do {
        res = (rand5() - 1)*5 + rand5();
    }while(res > 21);

    return res % 7 + 1;
}
