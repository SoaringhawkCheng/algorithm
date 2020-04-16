//
// Created by 成翔昊 on 2020/4/15.
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
    // FIFO的queue维护每行的节点
    // current queue生成next queue
    // current queue pop空，生成行遍历数据，再与next交换
    // 根据left_to_right决定是否要reverse level
    vector<vector<int>> levelOrderZigzag(TreeNode *root) {
        vector<vector<int>> result;

        if (root == NULL) return result;

        queue<TreeNode *> current, next;
        bool left_to_right = true;
        current.push(root);

        while (!current.empty()) {
            vector<int> level;
            while (!current.empty()) {
                TreeNode *node = current.front();
                current.pop();
                level.push_back(node->val);
                if (node->left != NULL) next.push(node->left);
                if (node->right != NULL) next.push(node->right);
            }
            if (!left_to_right) reverse(level.begin(),level.end());
            result.push_back(level);
            swap(next, current);
            left_to_right = !left_to_right;
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
    vector<vector<int>> result = s.levelOrderZigzag(root);
    for (int i = 0; i < result.size(); i++) {
        vector<int> level = result[i];
        for (int j = 0; j < level.size(); j++)
            cout << level[j] << " ";
        cout << endl;
    }
    cout << endl;
}