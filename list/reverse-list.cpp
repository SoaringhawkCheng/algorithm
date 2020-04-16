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
        ListNode *prev = head;
        ListNode *curr = prev->next;
        while (curr) {
            prev->next = curr->next;
            curr->next = dummy.next;
            dummy.next = curr;
            curr = prev->next;
        }
        return dummy.next;
    }
};

int main() {
    ListNode *head = new ListNode(0);
    ListNode *curr = head;
    for (int i = 1; i < 10; i++) {
        curr->next = new ListNode(i);
        curr = curr->next;
    }

    Solution s = Solution();
    head = s.reverseList(head);
    curr = head;
    while (curr) {
        cout << curr->val << " ";
        curr=curr->next;
    }
    cout << endl;
}