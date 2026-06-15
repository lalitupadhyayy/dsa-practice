// pattern : Sliding window
// Time complexity : O(n)
// Space complexity : O(1)
// dynamic sliding window question

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int low = 0;
        int high = 0;
        int sum = 0;
        int res = INT_MAX;

        // start hiring in company
        while(high< nums.size()){
            sum = sum + nums[high];

            // start firing from company
            while(sum>= target){
                int len = high - low + 1;
                // storing the minimum length
                res = min(res,len);
                //firing
                low++;
                sum = sum - nums[low - 1];
            }
            high++;
        }
        if(res == INT_MAX) return 0;
        else return res;
    }
};
