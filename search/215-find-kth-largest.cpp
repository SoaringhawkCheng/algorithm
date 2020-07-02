//
// Created by 成翔昊 on 2020/7/1.
//

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution1 {
public:
    int findKthLargest(vector<int> &nums, int k) {
        if (k > nums.size()) return INT_MIN;
        auto begin = nums.begin();
        auto end = nums.end();
        while (true) {
            auto pivot = partition(begin, end);
            if (pivot - nums.begin() + 1 == k) return *pivot;
            else if (pivot - nums.begin() + 1 < k) begin = pivot + 1;
            else end = pivot;
        }
    }

private:
    vector<int>::iterator partition(vector<int>::iterator begin, vector<int>::iterator end) {
        auto pivot = begin;
        auto index = next(begin);
        for (auto iter = next(begin); iter != end; iter++) {
            if (*iter > *pivot) {
                iter_swap(iter, index);
                index++;
            }
        }
        iter_swap(pivot, prev(index));
        return prev(index);
    }
};

class Solution2 {
public:
    int findKthLargest(vector<int> &nums, int k) {
        if (k > nums.size()) return INT_MIN;
        buildMaxHeap(nums);
        for (int i = 0; i < k; i++) {
            swap(nums[0], nums[nums.size() - 1 - i]);
            maxHeapify(nums, 0, nums.size() - 1 - i);
        }
        return nums[nums.size() - k];
    }

private:
    void buildMaxHeap(vector<int> &nums) {
        for (int i = nums.size() / 2 - 1; i >= 0; i--)
            maxHeapify(nums, i, nums.size());
    }

    void maxHeapify(vector<int> &nums, int index, int size) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int larger = index;
        if (left < size && nums[left] > nums[larger]) larger = left;
        if (right < size && nums[right] > nums[larger]) larger = right;
        if (larger != index) {
            swap(nums[larger], nums[index]);
            maxHeapify(nums, larger, size);
        }
    }
};

int main() {
    Solution2 s = Solution2();
    vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int target = 4;
    cout << s.findKthLargest(nums, target) << endl;
}