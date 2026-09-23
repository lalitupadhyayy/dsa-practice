// Problem: Find the Duplicate Number
// LeetCode: 287
// Pattern: Fast & Slow Pointers (Floyd's Cycle Detection)
//
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int slow = nums[0];
        int fast = nums[0];

        // Phase 1: Find intersection point
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // Phase 2: Find entrance of cycle
        slow = nums[0];

        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};
