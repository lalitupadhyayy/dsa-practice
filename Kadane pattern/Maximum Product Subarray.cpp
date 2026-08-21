// Problem: Maximum Product Subarray
// LeetCode: 152
// Pattern: Kadane's Algorithm (Modified)
//
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int currMax = nums[0];
        int currMin = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {

            // Negative number can turn min into max
            if (nums[i] < 0) {
                swap(currMax, currMin);
            }

            currMax = max(nums[i], currMax * nums[i]);
            currMin = min(nums[i], currMin * nums[i]);

            ans = max(ans, currMax);
        }

        return ans;
    }
};
