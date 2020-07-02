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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(-1);
        ListNode *p = &dummy;
        ListNode *p1 = l1, *p2 = l2;
        while (p1 && p2) {
            if (p1->val < p2->val) {
                p->next = p2;
                p2 = p2->next;
                p->next = p;
            } else {
                p->next = p1;
                p1 = p1->next;
                p->next = p;
            }
        }
        p->next = (p1 != nullptr ? p1 : p2);
        return dummy.next;
    }
};