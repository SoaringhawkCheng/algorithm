//
// Created by 成翔昊 on 2020/6/30.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 堆排序
    void heapSort(vector<int> &nums) {
        // 建堆 时间复杂度O(n)
        buildMaxHeap(nums);
        // 取出堆顶元素，顶重建堆O(nlogn)
        for (int i = nums.size() - 1; i > 0; i--) {
            swap(nums[0], nums[i]);
            maxHeapify(nums, 0, i); // log(n)
        }
    }

private:
    // 非叶子节点，由下向上逐个下滤
    void buildMaxHeap(vector<int> &nums) {
        for (int i = nums.size() / 2 - 1; i >= 0; i--)
            maxHeapify(nums, i, nums.size());
    }

    // 下滤，把当前节点向下寻找其应该在的位置，要求当前节点的左右子节点都满足堆的性质
    void maxHeapify(vector<int> &nums, int index, int size) {
        if (index >= size) return;
        // 找出节点和左右儿子中的最大者
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int larger = index;
        if (left < size && nums[left] > nums[index]) larger = left;
        if (right < size && nums[right] > nums[left]) larger = right;
        // 如果节点不是最大的
        if (larger != index) {
            // 交换节点
            swap(nums[index], nums[larger]);
            // 递归下滤
            maxHeapify(nums, larger, size);
        }
    }
};

int main() {
    Solution s = Solution();
    vector<int> nums = {4, 2, 8, 5, 7, 1, 0, 9, 3, 6};
    s.heapSort(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
}