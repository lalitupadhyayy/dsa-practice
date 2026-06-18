// Problem: Longest Substring with K Distinct Characters (medium)
// Geeks for geeks: 1
// problem level : medium
//
// Time Complexity: O(n+n) = O(n)
// Space Complexity: O(1)

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int high = 0, low = 0;
        int res = INT_MIN;
        //initializing hashmap
        unordered_map<int,int> f;

        for(high = 0; high <fruits.size(); high++){
            f[fruits[high]]++;

            while(f.size()>2){
                f[fruits[low]]--;
                if(f[fruits[low]] == 0)
                    f.erase(fruits[low]);
                low++;
            }

            int len = high - low + 1;
            res = max(res, len);
        }
        return res;
    }
};
