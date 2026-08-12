// Problem: Permutation in String
// LeetCode: 567
// Pattern: Sliding Window + Frequency Array
//
// Time Complexity: O(n + m)
// Space Complexity: O(1)

class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if (s1.size() > s2.size())
            return false;

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        // Frequency of characters in s1
        for (char c : s1)
            freq1[c - 'a']++;

        int windowSize = s1.size();

        // First window
        for (int i = 0; i < windowSize; i++)
            freq2[s2[i] - 'a']++;

        if (freq1 == freq2)
            return true;

        // Slide the window
        for (int right = windowSize; right < s2.size(); right++) {

            // Add new character
            freq2[s2[right] - 'a']++;

            // Remove old character
            freq2[s2[right - windowSize] - 'a']--;

            if (freq1 == freq2)
                return true;
        }

        return false;
    }
};
