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
    // curr=root
    // 一直遍历左子树，推入
    // 推出栈顶，加入结果
    // 如果有右儿子，curr=curr->right
    // 如果没有右儿子，curr=NULL(防止重复访问左子树)
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> stk;
        TreeNode *curr = root;
        while (curr != NULL || !stk.empty()) {
            while (curr) {
                stk.push(curr);
                curr = curr->left;
            }
            curr = stk.top();
            stk.pop();
            result.push_back(curr->val);
            if (curr->right) curr=curr->right;
            else curr=NULL;
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
    vector<int> result = s.inorderTraversal(root);
    for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
    cout << endl;
}