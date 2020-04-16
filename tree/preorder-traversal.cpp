//
// Created by 成翔昊 on 2020/4/15.
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
    // 前序遍历: 根左右
    // 推出根，加入结果，推入右子节点，左子节点
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;

        if (root == NULL) return result;

        stack<TreeNode *> stk;
        stk.push(root);

        while (!stk.empty()) {
            TreeNode *curr = stk.top();
            stk.pop();
            result.push_back(curr->val);
            if (curr->right) stk.push(curr->right);
            if (curr->left) stk.push(curr->left);
        }
        return result;
    }
};

int main() {
    vector<TreeNode> treelist;
    for (int i = 0; i < 8; ++i) {
        treelist.push_back(TreeNode(i));
    }
    TreeNode *root = &treelist[0];
    treelist[0].left = &treelist[1];
    treelist[0].right = &treelist[2];
    treelist[1].left = &treelist[3];
    treelist[1].right = &treelist[4];
    treelist[2].left = &treelist[5];
    treelist[4].left = &treelist[6];
    treelist[4].right = &treelist[7];

    Solution s = Solution();
    vector<int> result = s.preorderTraversal(root);
    for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
    cout << endl;
}