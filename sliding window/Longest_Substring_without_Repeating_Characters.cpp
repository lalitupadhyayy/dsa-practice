// Problem: Longest Substring without Repeating Characters (medium)
// Leetcode: 3
// problem level : medium
//
// Time Complexity: O(n+n) = O(n)
// Space Complexity: O(1)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int high = 0, low = 0;
        int res = INT_MIN;
        //initializing hashmap
        unordered_map<char,int> f;

        // add high in hashmap
        for(high=0; high < s.size(); high++){
            f[s[high]]++; // adding to hashmap
            int k = high - low + 1; // the substring size(length)

            while(f.size()<k){ 
                // erasing and decreasing the size of hashmap
                f[s[low]]--;
                if(f[s[low]] == 0)
                    f.erase(s[low]);
                low++;
                // again calculating k because chnge in low also affect the size of substring K
                k = high - low + 1;
            }
            // in last jst store the maximum length in result
            int len = high - low + 1;
            res = max(len,res);

        }
        if(res == INT_MIN){
            return 0;
        }
        return res;
    }
};
