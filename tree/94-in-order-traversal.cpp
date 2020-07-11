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
    // 遍历顺序 左中右
    // 首先一直遍历左儿子，推入栈
    // 推出栈顶元素
    // 如果有右儿子，遍历右儿子和右儿子的左子树，推入栈
    // 循环
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root==NULL) return result;
        stack<TreeNode *> stk;
        TreeNode *curr=root;

        // 初始化栈
        while(curr) {
            stk.push(curr);
            curr=curr->left;
        }

        // 循环计算结果
        while(!stk.empty()) {
            curr=stk.top();
            stk.pop();
            result.push_back(curr->val);
            if (curr->right) {
                curr=curr->right;

                // 推入右儿子及右儿子的左子树
                while(curr) {
                    stk.push(curr);
                    curr=curr->left;
                }
            }
        }
        return result;
    }
};
