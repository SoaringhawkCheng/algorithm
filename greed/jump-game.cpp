//
// Created by 成翔昊 on 2020/4/25.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 当前访问节点和该节点极其之前节点的最远到达节点
    // 这中间的点，如果没有更远的最远到达节点
    // 最远到达节点，即最终的最远到达节点
    bool canJump(const vector<int> &nums) {
        if (nums.size() <= 1) return true;
        int reach = 0;
        for (int i = 0; i <= reach && reach < nums.size(); ++i)
            reach = max(reach, i + nums[i]);
        return reach >= nums.size() - 1;
    }
};

int main() {
    Solution s = Solution();
    vector<int> nums1 = {2, 3, 1, 1, 4};
    vector<int> nums2 = {3, 2, 1, 0, 4};
    cout << s.canJump(nums1) << endl;
    cout << s.canJump(nums2) << endl;
}