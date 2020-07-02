//
// Created by 成翔昊 on 2020/7/2.
//

#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        ListNode dummy(INT_MIN);
        dummy.next=head;
        ListNode *curr = head;

        while (curr) {
            auto pos = findInsertPos(&dummy, curr->val);
            ListNode *tmp = curr->next;
            curr->next = pos->next;
            pos->next = curr;
            curr = tmp;
        }
        return dummy.next;
    }
    ListNode *findInsertPos(ListNode *head, int val) {
        ListNode *prev = NULL, *curr = head;
        while (curr&&curr->val < val) {
            prev = curr;
            curr = curr->next;
        }
        return prev;
    }
};