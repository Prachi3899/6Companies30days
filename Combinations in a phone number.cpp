class Solution {
public:
    void backtrack(string& digits, vector<string>& result, string& combination, vector<string>& mapping, int index) {
        // Base case: if the combination is of the same length as digits
        if (index == digits.size()) {
            result.push_back(combination);
            return;
        }

        // Get the letters corresponding to the current digit
        string letters = mapping[digits[index] - '0'];
        for (char letter : letters) {
            // Add the letter to the current combination
            combination.push_back(letter);
            // Move to the next digit
            backtrack(digits, result, combination, mapping, index + 1);
            // Backtrack: remove the last added letter
            combination.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        // Digit-to-letters mapping
        vector<string> mapping = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };

        vector<string> result;
        string combination;

        // Start backtracking from the first digit
        backtrack(digits, result, combination, mapping, 0);

        return result;
    }
};
