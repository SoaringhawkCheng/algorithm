//
// Created by 成翔昊 on 2020/4/25.
//

#include <iostream>
#include <vector>

using namespace std;

// f[j]表示以j结尾的字符串
// f[j] = max{f[j-1]+nums[j], nums[j]}
// result = max{f[j]}
class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        int result = nums[0];
        int f = 0;
        for (int i = 1; i < nums.size(); ++i) {
            f = max(f + nums[i], nums[i]);
            result = max(result, f);
        }
        return result;
    }
};

int main() {
    Solution s = Solution();
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << s.maxSubArray(nums) << endl;
}