//
// Created by 成翔昊 on 2020/4/14.
//

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    // 从未排列序列中找到最小元素，放到已排序序列后面
    void selectSort(vector<int> &nums) {
        int size = nums.size();
        for (int i = 0; i < size - 1; i++) {
            int index = i;
            for (int j = i + 1; j < size; j++) {
                if (nums[j] < nums[index]) index = j;
            }
            swap(nums[i], nums[index]);
        }
    }
    void heapSort(vector<int> &nums) {

    }
};

int main() {
    Solution s = Solution();
    vector<int> nums = {1, 4, 2, 8, 5, 7};
    s.selectSort(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
}