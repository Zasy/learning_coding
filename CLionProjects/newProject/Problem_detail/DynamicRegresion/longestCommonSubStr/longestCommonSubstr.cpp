//
// Created by zhanGGe on 2018/9/12.
// 最长公共子序列

int getLongestCommonSubstr(string s1, string s2){
    int len_1 = s1.size();
    int len_2 = s2.size();

    vector<vector<int>> dp(len_1 + 1, vector<int>(len_2, 0));

    for(int i=0; i <= len_1; i++){
        dp[i][0] = 0;
    }

    for (int i=0; i <= len_2; i++) dp[0][i] = 0;


    for(int i=1; i < len_1; i++) {
        for(int j = 1;j < len_2; j++){
            if(s1[i] == s2[j]) dp[i][j] = dp[i -1][j-1] + 1;
            else{
                dp[i][j] = max(dp[i][j -1], dp[i-1][j]);
            }
        }
    }

    return dp[len_1][len_2];
}
