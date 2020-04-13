#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums, vector<int> &new_nums) {
        if (nums.empty()) return 0;
        int index = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[index - 1] != nums[i])
                nums[index++] = nums[i];
        }
        for (int j = 0; j < index; j++) {
            new_nums.push_back(nums[j]);
        }
        return index;
    }
};

int main() {
    Solution s = Solution();
    vector<int> nums1 = {1, 1, 2, 2, 2, 3};
    vector<int> nums2;
    int total = s.removeDuplicates(nums1, nums2);
    cout << total << endl;
    for (int i = 0; i < nums2.size(); i++) {
        cout << nums2[i] << " ";
    }
    return 0;
}
