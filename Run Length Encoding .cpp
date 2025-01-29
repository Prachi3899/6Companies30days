class Solution {
  public:
    string encode(string s) {
        string encoded = "";  // Stores the result
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            char currentChar = s[i];
            int count = 1;
            
            // Count consecutive occurrences
            while (i + 1 < n && s[i] == s[i + 1]) {
                count++;
                i++;
            }
            
            // Append the character and its count to the result
            encoded += currentChar + to_string(count);
        }
        
        return encoded;
    }
};