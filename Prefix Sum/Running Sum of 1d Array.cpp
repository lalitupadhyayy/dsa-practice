// Problem: Running Sum of 1d Array
// LeetCode: 1480
// Pattern: Prefix Sum
//
// Time Complexity: O(n)
// Space Complexity: O(1) excluding output space

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            nums[i] = nums[i] + nums[i - 1];
        }

        return nums;
    }
};
