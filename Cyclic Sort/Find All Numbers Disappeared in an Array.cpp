// Problem: Find All Numbers Disappeared in an Array
// LeetCode: 448
// Pattern: Array + Cyclic Sort
//
// Time Complexity: O(n)
// Space Complexity: O(1) — excluding result/output space

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

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

        // Find indexes where the correct number is missing
        for (int i = 0; i < n; i++) {

            if (nums[i] != i + 1) {
                ans.push_back(i + 1);
            }
        }

        return ans;
    }
};
