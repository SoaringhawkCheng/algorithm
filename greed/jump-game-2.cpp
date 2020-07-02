//
// Created by 成翔昊 on 2020/4/25.
//

#include <iostream>
#include <vector>

using namespace std;

// 思路
// [0,0]，0最大能跳到10
// [1,10]节点，最少一次就可以到达
// [1,10]，其中5能跳到15，最远
// [11,15]节点，最少两次可以到达
// [1,10]最远只能跳到15，计算最少三次可以到达，只需要考虑[11,15]
// [11,15]，最远只能跳到15
// 停
class Solution {
public:
    int jump(const vector<int> &nums) {
        if (nums.size() <= 1) return 0;
        int step = 0, left = 0, right = 0;
        while (left <= right) {
            ++step;
            int max_right = right;
            for (int i = left; i <= right; ++i) {
                int new_right = nums[i] + i;
                if (new_right >= nums.size() - 1) return step;
                if (new_right > max_right) max_right = new_right;
            }
            left = right + 1;
            right = max_right;
        }
        return 0;
    }
};

int main() {
    Solution s = Solution();
    vector<int> nums1 = {2, 3, 1, 1, 4};
    vector<int> nums2 = {3, 2, 1, 0, 4};
    cout << s.jump(nums1) << endl;
    cout << s.jump(nums2) << endl;
}