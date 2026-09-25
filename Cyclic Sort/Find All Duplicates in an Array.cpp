// Problem: Find All Duplicates in an Array
// LeetCode: 442
// Pattern: Array + Cyclic Sort
// 
// Time Complexity: O(n)
// Space Complexity: O(1) — excluding result/output space
 
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
 
        int n = nums.size();
 
        // Put every number at its correct index
        for (int i = 0; i < n; i++) {
 
            int correctIndex = nums[i] - 1;
 
            if (nums[i] != nums[correctIndex]) {
                swap(nums[i], nums[correctIndex]);
                i--;  // check the new number at this index
            }
        }
 
        vector<int> ans;
 
        // Find indexes where the correct number is duplicated
        for (int i = 0; i < n; i++) {
 
            if (nums[i] != i + 1) {
                ans.push_back(nums[i]);
            }
        }
 
        return ans;
    }
};
