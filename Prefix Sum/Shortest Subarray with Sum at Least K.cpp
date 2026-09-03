// Problem: Shortest Subarray with Sum at Least K
// LeetCode: 862
// Pattern: Prefix Sum + Monotonic Deque
//
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {

        int n = nums.size();

        // Prefix sum
        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        deque<int> dq;
        int ans = n + 1;

        for (int i = 0; i <= n; i++) {

            // If current prefix - oldest prefix >= k,
            // we found a valid subarray.
            while (!dq.empty() &&
                   prefix[i] - prefix[dq.front()] >= k) {

                ans = min(ans, i - dq.front());
                dq.pop_front();
            }

            // Maintain increasing prefix sums
            while (!dq.empty() &&
                   prefix[i] <= prefix[dq.back()]) {

                dq.pop_back();
            }

            dq.push_back(i);
        }

        return ans == n + 1 ? -1 : ans;
    }
};
