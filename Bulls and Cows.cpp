class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        vector<int> secretCount(10, 0), guessCount(10, 0);

        // First pass: Count bulls and record unmatched digits
        for (int i = 0; i < secret.length(); ++i) {
            if (secret[i] == guess[i]) {
                bulls++; // Correct digit and position
            } else {
                secretCount[secret[i] - '0']++; // Increment frequency in secret
                guessCount[guess[i] - '0']++;   // Increment frequency in guess
            }
        }

        // Second pass: Count cows based on unmatched digits
        for (int i = 0; i < 10; ++i) {
            cows += min(secretCount[i], guessCount[i]); // Count common digits
        }

        // Construct the result string
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
