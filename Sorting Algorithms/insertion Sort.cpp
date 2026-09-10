class Solution {
public:

    vector<int> sortArray(vector<int>& nums) {

        int n = nums.size();

        // Start from the second element
        for (int i = 1; i < n; i++) {

            int key = nums[i];

            int j = i - 1;

            // Shift larger elements to the right
            while (j >= 0 && nums[j] > key) {

                nums[j + 1] = nums[j];
                j--;
            }

            // Put key at its correct position
            nums[j + 1] = key;
        }

        return nums;
    }
};
