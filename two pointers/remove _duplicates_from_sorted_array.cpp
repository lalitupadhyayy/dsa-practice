// Problem: Remove Duplicates from Sorted Array
// Platform: LeetCode
// Pattern: Two Pointers
// Appraoch: Optimal
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int officer  = 0;
        int res = 1;
        int cm = 1;
        while(cm < nums.size()){
            if(nums[cm]==nums[cm-1]){
                cm++;
                continue;
            }
            // unique found
            nums[officer+1] = nums[cm];
            officer++;
            res++;
            cm++;
        }
        return res;
    }    
};
