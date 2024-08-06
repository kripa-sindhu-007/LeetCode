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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* ans = nullptr;

        while (l1 != nullptr || l2 != nullptr || carry) {
            int sum = carry; // Start with carry from the previous iteration

            if (l1 != nullptr) {
                sum += l1->val; // Add value from l1
                l1 = l1->next;  // Move to the next node
            }

            if (l2 != nullptr) {
                sum += l2->val; // Add value from l2
                l2 = l2->next;  // Move to the next node
            }

            carry = sum / 10;        // Update carry
            int curr_val = sum % 10; // Current digit to store

            // Create a new node with the current value and add to the front
            ListNode* newNode = new ListNode(curr_val);
            newNode->next = ans;
            ans = newNode;
        }

        // Since we've been adding nodes to the front, we need to reverse the
        // result
        ListNode* prev = nullptr;
        ListNode* curr = ans;
        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }
};