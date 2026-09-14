// Problem: Sort an Array
// LeetCode: 912
// Pattern: Heap Sort
//
// Time Complexity: O(n log n)
// Space Complexity: O(1)

class Solution {
public:

    void heapify(vector<int>& nums, int n, int i) {
        int largest = i;

        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // Check left child
        if (left < n && nums[left] > nums[largest])
            largest = left;

        // Check right child
        if (right < n && nums[right] > nums[largest])
            largest = right;

        // If largest is not the root
        if (largest != i) {
            swap(nums[i], nums[largest]);

            // Fix the affected subtree
            heapify(nums, n, largest);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Build Max Heap
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(nums, n, i);
        }

        // Step 2: Extract elements one by one
        for (int i = n - 1; i > 0; i--) {

            // Move largest element to the end
            swap(nums[0], nums[i]);

            // Restore heap property
            heapify(nums, i, 0);
        }

        return nums;
    }
};
