// Problem: Remove Duplicates from Sorted Array II
// LeetCode: 80
// Pattern: Two Pointers
//
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int n = nums.size();
        if (n <= 2) return n;

        int j = 2;  // Start from index 2

        for (int i = 2; i < n; i++) {

            if (nums[i] != nums[j - 2]) {
                nums[j] = nums[i];
                j++;
            }
        }

        return j;
    }
};
