// Problem: Interval List Intersections
// LeetCode: 986
// Pattern: Intervals + Two Pointers
//
// Time Complexity: O(n + m)
// Space Complexity: O(1) — excluding result/output space

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList,
                                              vector<vector<int>>& secondList) {

        vector<vector<int>> ans;

        int i = 0, j = 0;

        while (i < firstList.size() && j < secondList.size()) {

            // Find overlapping range
            int start = max(firstList[i][0], secondList[j][0]);
            int end = min(firstList[i][1], secondList[j][1]);

            // If start <= end, intersection exists
            if (start <= end) {
                ans.push_back({start, end});
            }

            // Move the interval that ends first
            if (firstList[i][1] < secondList[j][1]) {
                i++;
            } else {
                j++;
            }
        }

        return ans;
    }
};
