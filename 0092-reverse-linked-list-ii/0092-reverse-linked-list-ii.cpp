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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right)
            return head;

        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;

        ListNode* preLeft = dummyHead;

        for (int i = 0; i < left - 1; i++)
            preLeft = preLeft->next;

        ListNode* startNode = preLeft->next;
        ListNode* currNode = startNode->next;

        for (int i = 0; i < right - left; i++) {
            ListNode* nextNode = currNode->next;
            currNode->next = preLeft->next;
            preLeft->next = currNode;
            startNode->next = nextNode;
            currNode = nextNode;
        }
        ListNode* result = dummyHead->next;
        delete dummyHead;
        return result;
    }
};