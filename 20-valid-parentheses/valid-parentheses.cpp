class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for(int i = 0; i < s.length(); i++) {

            // Opening brackets -> stack me store
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            }

            // Closing brackets -> stack ke top se check
            else {

                if(st.empty())
                    return false;

                if((s[i] == ')' && st.top() == '(') ||
                   (s[i] == '}' && st.top() == '{') ||
                   (s[i] == ']' && st.top() == '[')) {

                    st.pop();
                }

                else
                    return false;
            }
        }

        // Agar stack empty hai -> valid
        if(st.empty())
            return true;

        return false;
    }
};