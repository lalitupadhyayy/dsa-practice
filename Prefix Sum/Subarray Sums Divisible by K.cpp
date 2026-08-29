// Problem: Subarray Sums Divisible by K
// LeetCode: 974
// Pattern: Prefix Sum + Hash Map
//
// Time Complexity: O(n)
// Space Complexity: O(k)

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        unordered_map<int, int> mp;

        // Remainder 0 has occurred once
        mp[0] = 1;

        int prefixSum = 0;
        int ans = 0;

        for (int num : nums) {

            prefixSum += num;

            int rem = prefixSum % k;

            // Handle negative remainder
            if (rem < 0)
                rem += k;

            if (mp.find(rem) != mp.end()) {
                ans += mp[rem];
            }

            mp[rem]++;
        }

        return ans;
    }
};
