// Problem: Contiguous Array
// LeetCode: 525
// Pattern: Prefix Sum + Hash Map
//
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        unordered_map<int, int> mp;

        // prefix sum 0 occurs at index -1
        mp[0] = -1;

        int prefixSum = 0;
        int maxLength = 0;

        for (int i = 0; i < nums.size(); i++) {

            // Treat 0 as -1 and 1 as +1
            if (nums[i] == 0)
                prefixSum--;
            else
                prefixSum++;

            // Same prefix sum means equal number of 0s and 1s
            if (mp.find(prefixSum) != mp.end()) {

                maxLength = max(maxLength,
                                i - mp[prefixSum]);
            }
            else {
                // Store FIRST occurrence only
                mp[prefixSum] = i;
            }
        }

        return maxLength;
    }
};
