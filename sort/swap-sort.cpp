//
// Created by 成翔昊 on 2020/4/14.
//

#include<iostream>
#include<vector>
#include<iterator>

using namespace std;

class Solution {
public:
    // 相邻两个元素比较交换
    void bubbleSort(vector<int> &nums) {
        int size = nums.size();
        for (int i = 1; i < size; i--) {
            bool flag = false;
            for (int j = 0; j < size - i; j++) {
                if (nums[j + 1] < nums[j]) {
                    flag = true;
                    swap(nums[i], nums[j]);
                }
            }
            if (!flag) return;
        }
    }

    void quickSort(vector<int>::iterator begin, vector<int>::iterator end) {
        if (begin != end) {
            auto index = this->partition(begin, end);
            this->quickSort(begin, index);
            this->quickSort(next(index), end);
        }
    }

private:
    vector<int>::iterator partition(vector<int>::iterator begin, vector<int>::iterator end) {
        auto pivot = begin;
        auto index = next(begin);
        for (auto iter = next(begin); iter != end; iter++) {
            if (*iter < *pivot) {
                iter_swap(index, iter);
                index++;
            }
        }
        iter_swap(pivot, prev(index));
        return prev(index);
    }
};

int main() {
    Solution s = Solution();
    vector<int> nums = {4, 2, 8, 5, 7, 1, 0, 3, 9, 6};
    s.quickSort(nums.begin(), nums.end());
    for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++)
        cout << *iter << " ";
    cout << endl;
}