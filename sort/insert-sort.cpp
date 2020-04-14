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
            cout << "before: ";
            for (int k = 0; k <= i; k++) {
                cout << nums[k] << " ";
            }
            cout << endl;
            int num = nums[i];
            int j=i-1;
            while (j >= 0) {
                if (nums[j] > num) nums[j+1]=nums[j];

            }
            for (int j = i - 1; j >= 0; j--) {
                if (nums[j] > num) nums[j + 1] = nums[j];
                else {
                    nums[j + 1] = num;
                    break;
                }
            }
            cout << "end: ";
            for (int k = 0; k <= i; k++) {
                cout << nums[k] << " ";
            }
            cout << endl;
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