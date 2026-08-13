// Problem: Find All Anagrams in a String
// LeetCode: 438
// Pattern: Sliding Window + Frequency Array
//
// Time Complexity: O(n + m)
// Space Complexity: O(1)

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> ans;

        if (p.size() > s.size())
            return ans;

        vector<int> freqP(26, 0);
        vector<int> freqWindow(26, 0);

        // Frequency of characters in p
        for (char c : p) {
            freqP[c - 'a']++;
        }

        int windowSize = p.size();

        // Create the first window
        for (int i = 0; i < windowSize; i++) {
            freqWindow[s[i] - 'a']++;
        }

        if (freqP == freqWindow) {
            ans.push_back(0);
        }

        // Slide the window
        for (int right = windowSize; right < s.size(); right++) {

            // Add new character
            freqWindow[s[right] - 'a']++;

            // Remove character leaving the window
            freqWindow[s[right - windowSize] - 'a']--;

            // Check if current window is an anagram
            if (freqP == freqWindow) {
                ans.push_back(right - windowSize + 1);
            }
        }

        return ans;
    }
};
