//
// Created by 成翔昊 on 2020/7/3.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 有序数组中序遍历
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return sortedArrayToBST(nums.begin(), nums.end());
    }

private:
    TreeNode *sortedArrayToBST(vector<int>::iterator begin, vector<int>::iterator end) {
        if (begin >= end) return NULL;
        auto mid = begin + (end - begin) / 2;
        TreeNode *root = new TreeNode(*mid);
        root->left = sortedArrayToBST(begin, mid);
        root->right = sortedArrayToBST(mid + 1, end);
        return root;
    }
};