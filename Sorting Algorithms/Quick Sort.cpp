class Solution {
public:

    // Partition the array
    int partition(vector<int>& nums, int low, int high) {

        int pivot = nums[high];

        int i = low - 1;

        for (int j = low; j < high; j++) {

            if (nums[j] <= pivot) {
                i++;
                swap(nums[i], nums[j]);
            }
        }

        // Put pivot at its correct position
        swap(nums[i + 1], nums[high]);

        return i + 1;
    }


    // Quick Sort
    void quickSort(vector<int>& nums, int low, int high) {

        if (low >= high)
            return;

        // Find pivot's correct position
        int pivotIndex = partition(nums, low, high);

        // Sort left part
        quickSort(nums, low, pivotIndex - 1);

        // Sort right part
        quickSort(nums, pivotIndex + 1, high);
    }


    vector<int> sortArray(vector<int>& nums) {

        quickSort(nums, 0, nums.size() - 1);

        return nums;
    }
};
