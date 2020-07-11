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
    // 左右根
    // 首先遍历一遍左儿子，推入栈
    // 访问栈顶元素
    // 如果栈顶没有右儿子，或者右儿子进过栈刚被推出
    // 推出栈顶元素
    // 如果不是，遍历右儿子极其左儿子，推入栈
    // 循环
    vector<int> postorderTraversal(TreeNode *root) {
        stack<TreeNode *> stk;
        TreeNode *prev = NULL, *curr = root;
        vector<int> result;

        if (root==NULL) return result;

        while (curr) {
            stk.push(curr);
            curr = curr->left;
        }

        while (!stk.empty()) {
            curr = stk.top();
            if (curr->right==NULL||curr->right == prev) {
                stk.pop();
                prev = curr;
                result.push_back(curr->val);
            } else {
                curr = curr->right;
                while (curr) {
                    stk.push(curr);
                    curr = curr->left;
                }
            }
        }

        return result;
    }
};

int main() {

}