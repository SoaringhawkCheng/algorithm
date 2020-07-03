//
// Created by 成翔昊 on 2020/4/14.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void insertSort(vector<int> &nums) {
        int size = nums.size();
        for (int i = 1; i < size; i++) {
            int num = nums[i];
            int j=i-1;
            while(j>=0&&nums[j]>num) {
                nums[j+1]=nums[j];
                j--;
            }
            nums[j+1]=num;
        }
    }
};

int main() {
    Solution s = Solution();
    vector<int> nums = {4, 2, 8, 5, 7, 1, 0, 3, 9, 6};
    s.insertSort(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
}