class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";

        while (columnNumber > 0) {
            columnNumber--; // Adjust to 0-based indexing
            char ch = 'A' + (columnNumber % 26); // Map remainder to a character
            result = ch + result; // Prepend the character to the result
            columnNumber /= 26; // Move to the next digit
        }

        return result;
    }
};
