//
// Created by 成翔昊 on 2020/4/26.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() < 2) return true;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] = s[i] + 'a' - 'A';
            }
        }
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left] < 'a' || s[left] > 'z') {
                left++;
                continue;
            }
            if (s[right] < 'a' || s[right] > 'z') {
                right--;
                continue;
            }
            if (s[left] != s[right]) return false;
            left++, right--;
        }
        return true;
    }
};

int main() {
    Solution s = Solution();
    string str = "A man, a plan, a canal: Panama";
    cout << s.isPalindrome(str) << endl;
}