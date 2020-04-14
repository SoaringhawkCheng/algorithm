//
// Created by 成翔昊 on 2020/4/14.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    typedef vector<int>::iterator Iter;
public:
    void mergeSort(Iter begin, Iter end) {
        if (begin == end || begin + 1 == end) return;
        auto mid = begin + (end - begin) / 2;
        mergeSort(begin, mid);
        mergeSort(mid, end);
        this->merge(begin, mid, end);
    }

private:
    void merge(Iter begin, Iter mid, Iter end) {
        vector<int> nums;
        for (Iter iter = begin; iter != end; iter++) nums.push_back(*iter);
        auto left_iter = nums.begin(), right_iter = nums.begin() + (mid - begin);
        auto left_end = right_iter, right_end = nums.end();
        auto iter = begin;
        while (left_iter != left_end && right_iter != right_end) {
            if (*left_iter <= *right_iter) *iter++ = *left_iter++;
            else *iter++ = *right_iter++;
        }
        while (left_iter != left_end) *iter++ = *left_iter++;
        while (right_iter != right_end) *iter++ = *right_iter++;
    }
};

int main() {
    Solution s = Solution();
    vector<int> nums = {4, 2, 8, 5, 7, 1, 0, 9, 6, 3};
//    vector<int> nums = {};
    s.mergeSort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";
    cout << endl;
}