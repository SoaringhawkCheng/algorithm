//
// Created by 成翔昊 on 2020/7/11.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        if (s.size() == 0) return result;

        vector<string> path;
        dfs(result, path, s, 0);
        return result;
    }

private:
    void dfs(vector<vector<string>> &result, vector<string> &path, const string &s, int start) {
        if (start >= s.size()) {
            result.push_back(path);
            return;
        }
        for (int end = start; end < s.size(); end++) {
            if (isPalindrome(s, start, end)) {
                path.push_back(s.substr(start, end - start + 1));
                dfs(result, path, s, end + 1);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(const string &s, int start, int end) {
        while (start <= end && s[start] == s[end]) {
            start++;
            end--;
        }
        return start > end;
    }
};