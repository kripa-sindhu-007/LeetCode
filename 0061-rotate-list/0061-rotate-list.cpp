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
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || !head || !head->next)
            return head;

        // size of the LL
        int size_ll = 1;
        ListNode* tail = head;
        while (tail->next) {
            size_ll++;
            tail = tail->next;
        }

        // Nortmalize the value of K
        k = k % size_ll;
        if (k == 0)
            return head;

        // Find the new head after rotation
        ListNode* it = head;
        for (int i = 0; i < size_ll - k - 1; i++) {
            it = it->next;
        }

        // Make the new connection
        ListNode* newHead = it->next;
        it->next = nullptr;
        tail->next = head;

        return newHead;
    }
};