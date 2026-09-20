// Problem: Check if Intervals Intersect
// GFG: isIntersect
// Pattern: Merge Intervals
//
// Time Complexity: O(n log n)
// Space Complexity: O(1) — excluding sorting space

class Solution {
public:
    bool isIntersect(vector<vector<int>> intervals) {
        
        // Sort by starting time
        sort(intervals.begin(), intervals.end());

        for (int i = 1; i < intervals.size(); i++) {

            // Current interval starts before
            // previous interval ends
            if (intervals[i][0] <= intervals[i - 1][1]) {
                return true;
            }
        }

        return false;
    }
};
