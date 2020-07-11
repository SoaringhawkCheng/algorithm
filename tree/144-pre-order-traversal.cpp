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
    // 前序遍历，根左右
    // 推出根，插入右左节点
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root==NULL) return result;

        stack<TreeNode *> stk;
        stk.push(root);

        while(!stk.empty()) {
            TreeNode *curr=stk.top();
            stk.pop()
            result.push_back(curr->val);
            if (curr->right) stk.push(curr->right);
            if (curr->left) stk.push(curr->left);
        }
        return result;
    }
};