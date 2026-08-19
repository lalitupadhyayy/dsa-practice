// Problem: Circular Array Loop
// LeetCode: 457
// Pattern: Fast & Slow Pointers
//
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {

        int n = nums.size();

        for (int i = 0; i < n; i++) {

            bool forward = nums[i] > 0;

            int slow = i;
            int fast = i;

            while (true) {

                // Move slow one step
                int nextSlow = getNext(slow, nums);

                // Invalid direction or self-loop
                if (nextSlow == -1 ||
                    (nums[nextSlow] > 0) != forward) {
                    break;
                }

                // Move fast one step
                int nextFast = getNext(fast, nums);

                if (nextFast == -1 ||
                    (nums[nextFast] > 0) != forward) {
                    break;
                }

                // Move fast second step
                nextFast = getNext(nextFast, nums);

                if (nextFast == -1 ||
                    (nums[nextFast] > 0) != forward) {
                    break;
                }

                slow = nextSlow;
                fast = nextFast;

                if (slow == fast)
                    return true;
            }
        }

        return false;
    }

private:
    int getNext(int index, vector<int>& nums) {

        int n = nums.size();

        // A cycle of length 1 is not allowed
        int next = ((index + nums[index]) % n + n) % n;

        if (next == index)
            return -1;

        return next;
    }
};
