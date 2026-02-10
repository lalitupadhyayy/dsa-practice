// Problem: Squares of a Sorted Array
// Platform: LeetCode (977)
// Pattern: Two Pointers
// Time Complexity: O(n)
// Space Complexity: O(n)


class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> arr1;
        vector<int> arr2;

        // split the main array in two diff arrays.. +ve and -ve
        for(int i=0; i< nums.size(); i++){
            if(nums[i]<0){
                arr1.push_back(nums[i]);
            }
            else{
                arr2.push_back(nums[i]);
            }
        }

        // when if all the elements are positive
        if(arr1.size() == 0){
            for(int i =0; i< arr2.size(); i++){
                arr2[i] = arr2[i]*arr2[i];
            }
            return arr2;
        }

        // when if all the elements are negative
        if(arr2.size() == 0){
            for(int i = 0;i < arr1.size();i++){
                arr1[i] = arr1[i]* arr1[i];
            }
            reverse(arr1.begin(), arr1.end());
            return arr1;
        }

        // when elements are both positive and negetive in array

        int n = arr1.size();
        int m = arr2.size();
        int id = 0;
        int i = 0;
        int j = 0;

        for(int i = 0; i<m;i++){
            arr2[i]= arr2[i] * arr2[i];
        }

        for(int i = 0; i<n; i++){
            arr1[i]= arr1[i] * arr1[i];
        }
        reverse(arr1.begin(), arr1.end());

        // merge two sorted arrays
        vector<int> res(n+m);      

         while(i<n && j<m){
            if(arr1[i]<arr2[j]){
                res[id]= arr1[i];
                i++;
                id++;
            }
            else{
                res[id]=arr2[j];
                j++;
                id++;
            }
         }
         while(i<n){
            res[id]= arr1[i];
                i++;
                id++;
         }
         while(j<m){
            res[id]=arr2[j];
                j++;
                id++;
         }
         return res;
    }
};
