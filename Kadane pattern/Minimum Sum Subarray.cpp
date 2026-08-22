// Problem: Minimum Sum Subarray
// Pattern: Kadane's Algorithm (Modified)
//
// Time Complexity: O(n)
// Space Complexity: O(1)

int minSubarraySum(vector<int>& arr) {

    int currentSum = arr[0];
    int minSum = arr[0];

    for (int i = 1; i < arr.size(); i++) {

        currentSum = min(arr[i], currentSum + arr[i]);

        minSum = min(minSum, currentSum);
    }

    return minSum;
}
