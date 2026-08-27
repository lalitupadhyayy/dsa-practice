// Problem: Subarray Sum Equals K
// LeetCode: 560
// Pattern: Prefix Sum + Hash Map
//
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> mp;

        // Prefix sum = 0 has occurred once
        mp[0] = 1;

        int prefixSum = 0;
        int count = 0;

        for (int num : nums) {

            prefixSum += num;

            // We need:
            // prefixSum - previousPrefix = k
            // Therefore:
            // previousPrefix = prefixSum - k

            if (mp.find(prefixSum - k) != mp.end()) {
                count += mp[prefixSum - k];
            }

            mp[prefixSum]++;
        }

        return count;
    }
};
