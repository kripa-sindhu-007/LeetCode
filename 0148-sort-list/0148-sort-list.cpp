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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* midNode = getMid(head);
        ListNode* leftHalf = head;
        ListNode* rightHalf = midNode->next;
        midNode->next = nullptr;

        ListNode* sortedLeft = sortList(leftHalf);
        ListNode* sortedRight = sortList(rightHalf);

        return mergeList(sortedLeft, sortedRight);
    }

private:
    ListNode* getMid(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* mergeList(ListNode* p, ListNode* q) {
        ListNode* dummyHead = new ListNode(-1);
        ListNode* curr = dummyHead;

        while (p && q) {
            if (p->val <= q->val) {
                curr->next = p;
                p = p->next;
            } else {
                curr->next = q;
                q = q->next;
            }
            curr = curr->next;
        }
        if (p)
            curr->next = p;
        if (q)
            curr->next = q;
        ListNode* head = dummyHead->next;
        delete (dummyHead);
        return head;
    }
};