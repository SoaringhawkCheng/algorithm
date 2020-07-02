//
// Created by 成翔昊 on 2020/4/25.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // f[i]表示走到i剩余最大步数
    // f[i] = max(f[i-1]-1, nums[i-1]-1)
    bool canJump(const vector<int> &nums) {
        vector<int> f(nums.size());
        f[0] = 0;
        for (int i = 1; i < nums.size(); i++) {
            f[i] = max(f[i - 1], nums[i - 1]) - 1;
            if (f[i] < 0) return false;
        }
        return true;
    }
};

int main() {
    Solution s = Solution();
    vector<int> nums1 = {2, 3, 1, 1, 4};
    vector<int> nums2 = {3, 2, 1, 0, 4};
    cout << s.canJump(nums1) << endl;
    cout << s.canJump(nums2) << endl;
}