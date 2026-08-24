// Problem: Maximum Absolute Sum of Any Subarray
// LeetCode: 1749
// Pattern: Kadane's Algorithm (Modified)
//
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {

        int maxEnding = nums[0];
        int minEnding = nums[0];

        int maxSum = nums[0];
        int minSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {

            // Kadane for maximum subarray sum
            maxEnding = max(nums[i], maxEnding + nums[i]);
            maxSum = max(maxSum, maxEnding);

            // Kadane for minimum subarray sum
            minEnding = min(nums[i], minEnding + nums[i]);
            minSum = min(minSum, minEnding);
        }

        return max(abs(maxSum), abs(minSum));
    }
};
