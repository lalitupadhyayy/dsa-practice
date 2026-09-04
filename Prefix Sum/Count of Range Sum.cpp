// Problem: Count of Range Sum
// LeetCode: 327
// Pattern: Prefix Sum + Merge Sort
//
// Time Complexity: O(n log n)
// Space Complexity: O(n)

class Solution {
public:

    long long mergeSort(vector<long long>& prefix, int left, int right,
                        long long lower, long long upper) {

        if (left >= right)
            return 0;

        int mid = left + (right - left) / 2;

        long long count = 0;

        count += mergeSort(prefix, left, mid, lower, upper);
        count += mergeSort(prefix, mid + 1, right, lower, upper);

        // Count valid range sums
        int low = mid + 1;
        int high = mid + 1;

        for (int i = left; i <= mid; i++) {

            while (low <= right &&
                   prefix[low] - prefix[i] < lower) {
                low++;
            }

            while (high <= right &&
                   prefix[high] - prefix[i] <= upper) {
                high++;
            }

            count += high - low;
        }

        // Merge the two sorted halves
        vector<long long> temp;

        int i = left;
        int j = mid + 1;

        while (i <= mid && j <= right) {

            if (prefix[i] <= prefix[j])
                temp.push_back(prefix[i++]);
            else
                temp.push_back(prefix[j++]);
        }

        while (i <= mid)
            temp.push_back(prefix[i++]);

        while (j <= right)
            temp.push_back(prefix[j++]);

        for (int k = 0; k < temp.size(); k++)
            prefix[left + k] = temp[k];

        return count;
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {

        int n = nums.size();

        // Prefix sums
        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        return mergeSort(prefix, 0, n, lower, upper);
    }
};
