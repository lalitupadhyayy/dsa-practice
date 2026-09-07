class Solution {
public:

    vector<int> sortArray(vector<int>& nums) {

        int n = nums.size();

        for (int i = 0; i < n - 1; i++) {

            // Assume current element is minimum
            int minIndex = i;

            // Find minimum element in remaining array
            for (int j = i + 1; j < n; j++) {

                if (nums[j] < nums[minIndex]) {
                    minIndex = j;
                }
            }

            // Put minimum element at correct position
            swap(nums[i], nums[minIndex]);
        }

        return nums;
    }
};
