//
// Created by zhanGGe on 2018/9/12.
// 最长无重复字符的字符串
// 采用动态规划 命令为当前最长的无重复字符的字符串的长度

int lengthOfLongestSubstring(string s) {
    int len = s.size();
    if (len == 0) return 0;
    int m   = 1;
    int cur = 1;
    vector<int> record(200, -1);
    record[s[0]] = 0;
    for(int i=1; i < len; i++){

        if(record[s[i]] == -1 ||record[s[i]] < (i - cur) ) {
            cur = cur + 1;
        }else{
            cur = i - record[s[i]];
        }
        record[s[i]] = i;
        m = (cur > m)? cur: m;
    }
    return m;
}

