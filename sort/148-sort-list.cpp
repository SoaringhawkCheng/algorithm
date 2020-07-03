//
// Created by 成翔昊 on 2020/7/2.
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
    ListNode *sortList(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *fast = head, *slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *head2=slow->next;
        slow->next=NULL;
        head=sortList(head);
        head2=sortList(head2);
        return mergeTwoLists(head,head2);
    }
private:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(-1);
        ListNode *curr=&dummy;
        while(l1&&l2) {
            if (l1->val<l2->val) {
                curr->next=l1;
                l1=l1->next;
            } else {
                curr->next=l2;
                l2=l2->next;
            }
            curr=curr->next;
        }
        while(l1) {
            curr->next=l1;
            l1=l1->next;
            curr=curr->next;
        }
        while(l2) {
            curr->next=l2;
            l2=l2->next;
            curr=curr->next;
        }
        return dummy.next;
    }
};