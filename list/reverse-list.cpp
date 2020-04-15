//
// Created by 成翔昊 on 2020/4/14.
//

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        if (head == NULL) return NULL;

        ListNode dummy(-1);
        dummy.next = head;
        ListNode *prev =head;
        ListNode *next = head->next;
    }
};

int main() {
    ListNode head = new ListNode(0);
    ListNode curr = head;
    for (int i = 1; i < 10; i++) {
        curr->next = new ListNode(i);
        curr = curr->next;
    }

    Solution s = Solution();
    curr = head = s.reverseList(head);
    while (curr) {
        cout << curr->val << " ";
    }
    cout << endl;
}