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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ans = new ListNode(0);
        ListNode* ptr = ans;
        int sum = 0;
        while (head != nullptr) {
            if (head->val != 0) {
                sum += head->val;

            } else {
                ptr->next = new ListNode(sum);
                ptr = ptr->next;
                sum = 0;
            }
            head = head->next;
        }
        return ans->next->next;
    }
};