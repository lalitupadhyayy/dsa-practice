// Problem: Segregate 0s and 1s
// Pattern: Two Pointers
//
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        // code here
        int i =0 , j = arr.size() - 1;
        
        while(i<j){
            
            if(arr[i]==1){
                if(arr[j]==0){
                    swap(arr[i],arr[j]);
                    i++;
                    j--;
                }
                else{
                    j--;
                }
            }
            else{
                i++;
            }
        }
    }
};
