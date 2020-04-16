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
    // 遍历左子树，推入
    // 如果栈顶元素有右子树，curr=top->right，重新走流程
    // 如果栈顶元素没有右子树，推出，加入结果，prev=curr(防止重复访问右子树),curr=NULL(防止重复访问右子树)
    // 为防止重复访问右子树，需要prev
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> stk;
        TreeNode *curr=root, *prev=NULL;
        while(curr!=NULL||!stk.empty()) {
            while(curr) {
                stk.push(curr);
                curr=curr->left;
            }
            curr = stk.top();
            if(curr->right==NULL||curr->right==prev) {
                result.push_back(curr->val);
                stk.pop();
                prev=curr;
                curr=NULL;
            } else {
                curr=curr->right;
            }
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
    vector<int> result = s.postorderTraversal(root);
    for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
    cout << endl;
}