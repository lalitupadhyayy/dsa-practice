// Problem: Find Pivot Index
// LeetCode: 724
// Pattern: Prefix Sum
//
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int totalSum = 0;

        for (int x : nums) {
            totalSum += x;
        }

        int leftSum = 0;

        for (int i = 0; i < nums.size(); i++) {

            int rightSum = totalSum - leftSum - nums[i];

            if (leftSum == rightSum) {
                return i;
            }

            leftSum += nums[i];
        }

        return -1;
    }
};
