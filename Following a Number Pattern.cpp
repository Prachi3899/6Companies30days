class Solution{   
public:
    string printMinNumberForPattern(string S) {
        string result = "";  
        stack<int> st;
        int num = 1;  // Start with number 1

        for (char c : S) {
            st.push(num++);  // Push the current number

            // If 'I' is encountered, pop all elements from the stack
            if (c == 'I') {
                while (!st.empty()) {
                    result += to_string(st.top());
                    st.pop();
                }
            }
        }

        // Push the last number
        st.push(num);

        // Pop remaining elements from the stack
        while (!st.empty()) {
            result += to_string(st.top());
            st.pop();
        }

        return result;
    }
};