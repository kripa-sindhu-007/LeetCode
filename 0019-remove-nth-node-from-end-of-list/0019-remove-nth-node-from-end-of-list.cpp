/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 1;
        ListNode* temp = head;
        while (temp->next) {
            size++;
            temp = temp->next;
        }

        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;

        temp = dummyHead;
        for (int i = 0; i < size - n; i++) {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        ListNode* result = dummyHead->next;
        delete (dummyHead);
        return result;
    }
};