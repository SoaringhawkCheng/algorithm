//
// Created by 成翔昊 on 2020/6/30.
//

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const int ASCII_MAX = 255;
        vector<int> last(ASCII_MAX, -1);
        int maxlen = 0;
        int begin = 0;
        for (int i = 0; i < s.size(); i++) {
            if (last[s[i]] >= begin) {
                maxlen = max(i - begin, maxlen);
                begin = last[s[i]] + 1;
            }
            last[s[i]] = i;
        }
        // 最后一次可能不重复，但是没计算入maxlen
        return max((int)s.size() - begin, maxlen);
    }
};

int main() {
    string str = "\"\"";
    Solution s = Solution();
    cout << s.lengthOfLongestSubstring(str) << endl;
}