// Problem: Meeting Rooms II
// GFG: Meeting Rooms
// Pattern: Intervals + Min Heap
//
// Time Complexity: O(n log n)
// Space Complexity: O(n)

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {

        if (intervals.empty())
            return 0;

        // Sort meetings by start time
        sort(intervals.begin(), intervals.end());

        // Min heap stores ending times
        priority_queue<int, vector<int>, greater<int>> pq;

        pq.push(intervals[0][1]);

        for (int i = 1; i < intervals.size(); i++) {

            // If the earliest meeting has ended,
            // reuse that room
            if (intervals[i][0] >= pq.top()) {
                pq.pop();
            }

            // Add current meeting's ending time
            pq.push(intervals[i][1]);
        }

        return pq.size();
    }
};
