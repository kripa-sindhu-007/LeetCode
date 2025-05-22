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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* dummyHead = new ListNode(-101);
        dummyHead->next = head;
        ListNode* curr = dummyHead;

        while (curr->next && curr->next->next) {
            if (curr->next->val == curr->next->next->val) {
                int dup_val = curr->next->val;
                while (curr->next && curr->next->val == dup_val) {
                    ListNode* temp = curr->next;
                    curr->next = curr->next->next;
                    delete temp;
                }
            } else {
                curr = curr->next;
            }
        }
        ListNode* result = dummyHead->next;
        delete dummyHead;
        return result;
    }
};