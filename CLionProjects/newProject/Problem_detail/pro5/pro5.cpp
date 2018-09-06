//
// Created by zhanGGe on 2018/9/4.
// 二维数组中的查找
// 二维数组的规律为从左到右增大， 从上到下增大
// 查找问题归结为二分查找法得问题
// 可总结点: 二分查找的细节分类问题 和 范围查找的问题
// 携程题目的另外两个总结点: LRU问题 和 多进制转换的问题 包括 int到 string


bool isExisted(vector<vector<int>> map_data, int val) {
    int row_data = map_data.size();
    if (row_data == 0) return false;

    int col_data = map_data[0].size();
    int x = col_data - 1;
    int y = 0;

    while(y < row_data && x >= 0) {
        if(map_data[y][x] == val) {
            return ture;
        }else if(map_data[y][x] > val) {
            x--
        }else {
            y++
        }
    }

    return false;
}




