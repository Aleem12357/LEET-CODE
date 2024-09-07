class Solution {
public:
    string longestPalindrome(string s) {
         int start = 0, end = 0; // To keep track of the start and end indices of the longest palindromic substring

        for (int i = 0; i < s.size(); i++) {
            // Odd-length palindromes (single character center)
            auto [l1, r1] = expandAroundCenter(s, i, i);
            // Even-length palindromes (center between characters)
            auto [l2, r2] = expandAroundCenter(s, i, i + 1);
            
            // Update the maximum palindrome found
            if (r1 - l1 > end - start) {
                start = l1;
                end = r1;
            }
            if (r2 - l2 > end - start) {
                start = l2;
                end = r2;
            }
        }

        return s.substr(start, end - start + 1);
    }
      // Helper function to expand around the center
    pair<int, int> expandAroundCenter(const string &s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return {left + 1, right - 1}; // Return the valid range of the palindrome
    }
};