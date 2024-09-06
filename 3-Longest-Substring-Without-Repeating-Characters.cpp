class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_map<char, int> index;
       int start=0,end=0,max_char=0;
       for(end;end<s.length();end++){
        char currentChar=s[end];
        if (index.find(currentChar) != index.end() && index[currentChar] >= start) {
                // Move the start to the right of the last occurrence of the current character
                start = index[currentChar] + 1;
            }
            
            // Update the last index of the current character
            index[currentChar] = end;
            
            // Calculate the length of the current substring and update max_char if needed
            max_char = std::max(max_char, end - start + 1);
        }
        
        return max_char;
    }
};