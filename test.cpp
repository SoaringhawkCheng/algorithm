#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> find_path(TreeNode *root, int target) {
        vector<vector<int>> result;
        if (root == NULL) return result;

        stack<TreeNode *> stk;
        vector<int> path;
        stk.push(root);
        path.push_back(root->val);
        int sum = root->val;
        dfs(stk, path, sum, target, result);
        return result;
    }

    void dfs(stack<TreeNode *> &stk, vector<int> &path, int &sum, const int &target, vector<vector<int>> &result) {
        auto curr = stk.top();

        if (curr->left == NULL && curr->right == NULL) {
            if (sum == target) result.push_back(path);
            return;
        }

        if (curr->left) {
            stk.push(curr->left);
            path.push_back(curr->left->val);
            sum = sum + curr->left->val;
            dfs(stk, path, sum, target, result);
            sum = sum - curr->left->val;
            stk.pop();
            path.pop_back();
        }
        if (curr->right) {
            stk.push(curr->right);
            path.push_back(curr->right->val);
            sum = sum + curr->right->val;
            dfs(stk, path, sum, target, result);
            sum = sum - curr->right->val;
            stk.pop();
            path.pop_back();
        }
    }
};