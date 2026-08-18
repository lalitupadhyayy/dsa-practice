// Problem: Reorder List
// LeetCode: 143
// Pattern: Fast & Slow Pointers + In-place Reversal + Two Pointers
//
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:

    ListNode* reverseList(ListNode* head) {

        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {

            ListNode* next = curr->next;

            curr->next = prev;

            prev = curr;
            curr = next;
        }

        return prev;
    }

    void reorderList(ListNode* head) {

        if (head == nullptr || head->next == nullptr)
            return;

        // Step 1: Find the middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != nullptr &&
               fast->next->next != nullptr) {

            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half
        ListNode* second = reverseList(slow->next);

        // Cut the list into two halves
        slow->next = nullptr;

        // Step 3: Merge the two halves alternately
        ListNode* first = head;

        while (second != nullptr) {

            ListNode* firstNext = first->next;
            ListNode* secondNext = second->next;

            first->next = second;
            second->next = firstNext;

            first = firstNext;
            second = secondNext;
        }
    }
};
