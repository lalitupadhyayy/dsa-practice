// Problem level = easy
// pattern = sliding window
// time complexity = O(n)
// Space somplexity = O(1)
class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int low = 0, high = k-1;
          int sum = 0;
          int res = 0;
          // information of first window
          for(int i=low;i<=high;i++){
              sum = sum + arr[i];
          }
          
          // information of further windows
          while(high< arr.size()){
              // store the maximum sum in result
              res = max(res,sum);
              // shift of window
              low++;
              high++;
              if(high == arr.size())
                break;
                
              sum = sum - arr[low-1];
              sum = sum + arr[high];
              
          }
          return res;
    }
};
