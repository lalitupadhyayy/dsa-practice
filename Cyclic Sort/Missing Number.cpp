// Problem: Missing Number
// LeetCode: 268
// Pattern: Array + Math
//
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int n = nums.size();

        int expectedSum = n * (n + 1) / 2;

        int actualSum = 0;

        for (int num : nums) {
            actualSum += num;
        }

        return expectedSum - actualSum;
    }
};
