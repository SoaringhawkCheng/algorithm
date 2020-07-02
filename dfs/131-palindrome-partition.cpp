//
// Created by 成翔昊 on 2020/4/25.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string> > partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        dfs(s, path, result, 0);
        return result;
    }

    void dfs(string &s, vector<string> &path, vector<vector<string>> &result, int start) {
        if (start == s.size()) {
            result.push_back(path);
            return;
        }
        for (int i = start; i < s.size(); i++) {
            if (isPalindrome(s, start, i)) {
                path.push_back(s.substr(start, i - start + 1));
                dfs(s, path, result, i + 1);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(const string &s, int start, int end) {
        while (start < end && s[start] == s[end]) {
            ++start;
            --end;
        }
        return start >= end;
    }
};

int main() {

}
