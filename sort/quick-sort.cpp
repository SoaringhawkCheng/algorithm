//
// Created by 成翔昊 on 2020/4/17.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void quickSort(vector<int>::iterator begin, vector<int>::iterator end) {
        if (begin < end) {
            auto pivot = partition(begin, end);
            quickSort(begin, pivot);
            quickSort(next(pivot), end);
        }
    }

private:
    // (pivot, index)开区间是比pivot小的值，最后将prev(index)和pivot交换
    vector<int>::iterator partition(vector<int>::iterator begin, vector<int>::iterator end) {
        auto pivot = begin;
        auto index = next(begin);
        for (auto iter = next(begin); iter != end; ++iter) {
            if (*iter < *pivot) {
                iter_swap(iter, index);
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