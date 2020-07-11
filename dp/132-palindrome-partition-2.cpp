//
// Created by 成翔昊 on 2020/4/25.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // f[i,j]表示i到j的mincut
    // f[i,j]=min{f[i,k]+f[k+1,j]}
    int minCut(const string &s) {
        const int size = s.size();
        if (size < 2) return 0;

        vector<vector<bool>> is_palindrome(size, vector<bool>(size, false));
        vector<int> min_cut; // 以index开头的字符串的最小分割数

        // 字符串初始min_cut是len-1
        for (int i = 0; i <= size; i++) min_cut.push_back(size - 1 - i);

        // 从size-1到0计算min_cut
        for (int i = size - 1; i >= 0; i--) {
            for (int j = i; j < size; j++) {
                if (s[i] == s[j] && (j - i < 2 || is_palindrome[i + 1][j - 1])) {
                    is_palindrome[i][j] = true;
                    min_cut[i] = min(min_cut[i], min_cut[j + 1] + 1);
                }
            }
        }
        return min_cut[0];
    }
};