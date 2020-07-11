//
// Created by 成翔昊 on 2020/7/3.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> result;
        if (root == NULL) return result;

        queue<TreeNode *> queue;
        TreeNode *curr = root;
        queue.push(curr);

        while (!queue.empty()) {
            vector<int> level;
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                curr=queue.front();
                queue.pop();
                level.push_back(curr->val);
                if (curr->left) queue.push(curr->left);
                if (curr->right) queue.push(curr->right);
            }
            result.push_back(level);
        }
        return result;
    }
};