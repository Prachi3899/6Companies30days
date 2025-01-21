class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";

        // Define the words for numbers
        vector<string> belowTwenty = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
                                      "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
                                      "Seventeen", "Eighteen", "Nineteen"};
        vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        vector<string> thousands = {"", "Thousand", "Million", "Billion"};

        // Helper function to convert numbers less than 1000
        auto threeDigitToWords = [&](int n) -> string {
            string result;
            if (n >= 100) {
                result += belowTwenty[n / 100] + " Hundred";
                n %= 100;
                if (n > 0) result += " ";
            }
            if (n >= 20) {
                result += tens[n / 10];
                n %= 10;
                if (n > 0) result += " ";
            }
            if (n > 0) {
                result += belowTwenty[n];
            }
            return result;
        };

        string result;
        int groupIndex = 0;

        while (num > 0) {
            int chunk = num % 1000;
            if (chunk > 0) {
                string chunkWords = threeDigitToWords(chunk);
                if (!chunkWords.empty()) {
                    if (!result.empty()) result = " " + result;
                    result = chunkWords + (thousands[groupIndex].empty() ? "" : " " + thousands[groupIndex]) + result;
                }
            }
            num /= 1000;
            ++groupIndex;
        }

        return result;
    }
};
