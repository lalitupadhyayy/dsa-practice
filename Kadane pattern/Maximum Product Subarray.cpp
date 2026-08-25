// Problem: Maximum Product Subarray
// LeetCode: 152
// Pattern: Kadane's Algorithm (Modified)
//
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int maxEnd = nums[0];
        int minEnd = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {

            int v1 = nums[i];
            int v2 = maxEnd * nums[i];
            int v3 = minEnd * nums[i];

            maxEnd = max(v1, max(v2,v3));
            minEnd = min(v1, min(v2,v3));

            ans = max(ans, max(maxEnd,minEnd));
            
        }

        return ans;
    }
};
