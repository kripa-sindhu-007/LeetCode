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
        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;

        ListNode* slow = dummyHead;
        ListNode* fast = dummyHead;

        for (int i = 0; i < n + 1; i++) {
            fast = fast->next;
        }
        while (fast) {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* to_delete = slow->next;
        slow->next = slow->next->next;
        delete (to_delete);

        ListNode* result = dummyHead->next;
        delete (dummyHead);
        return result;
    }
};