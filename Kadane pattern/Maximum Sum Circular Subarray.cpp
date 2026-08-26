// Problem: Maximum Sum Circular Subarray
// LeetCode: 918
// Pattern: Kadane's Algorithm (Modified)
//
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int total = 0;

        int maxEnding = 0;
        int maxSum = INT_MIN;

        int minEnding = 0;
        int minSum = INT_MAX;

        for (int x : nums) {

            total += x;

            maxEnding = max(x, maxEnding + x);
            maxSum = max(maxSum, maxEnding);

            minEnding = min(x, minEnding + x);
            minSum = min(minSum, minEnding);
        }

        // All numbers are negative
        if (maxSum < 0)
            return maxSum;

        return max(maxSum, total - minSum);
    }
};
