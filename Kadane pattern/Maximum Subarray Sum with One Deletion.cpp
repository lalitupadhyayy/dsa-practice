// Problem: Maximum Subarray Sum with One Deletion
// LeetCode: 1186
// Pattern: Kadane's Algorithm (Modified)
//
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maximumSum(vector<int>& arr) {

        int noDelete = arr[0];   // Best sum ending here without deletion
        int oneDelete = 0;       // Best sum ending here with one deletion

        int ans = arr[0];

        for (int i = 1; i < arr.size(); i++) {

            // If we delete arr[i], previous subarray had no deletion
            oneDelete = max(noDelete, oneDelete + arr[i]);

            // Normal Kadane
            noDelete = max(arr[i], noDelete + arr[i]);

            ans = max(ans, max(noDelete, oneDelete));
        }

        return ans;
    }
};
