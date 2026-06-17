// Problem: Longest Substring with K Distinct Characters (medium)
// Geeks for geeks: 1
// pattern : SW
//
// Time Complexity: O(n+n) = O(n)
// Space Complexity: O(1)

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int high = 0, low = 0;
        int res = INT_MIN;
        // initializing hashmap
        unordered_map<char,int> f;
        
        // to traverse all the string
        for(high = 0; high< s.size(); high++){
            f[s[high]]++; // to add data in hashmap
            
            while(f.size()>k){ // to check when size is more than target
                f[s[low]]--; // decrease the count in hasmap
                if(f[s[low]]==0)
                    f.erase(s[low]); // remove character if count gets 0
                low++;
            }
            
            if(f.size()==k){ // if target reaches then store it & traverse for next
                int len = high - low + 1;
                res = max(res,len);
            }
        }
         if(res==INT_MIN) // if no such string
        return -1;

        return res;
    }
};
