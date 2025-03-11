
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26, 0);
        vector<bool> vis(26, false);
        stack<char> st;

        for (char i : s) freq[i - 'a']++;

        for (char i : s) {
            if (vis[i - 'a']) {
                freq[i - 'a']--;
                continue;
            }
            while (!st.empty() && st.top() > i && freq[st.top() - 'a'] > 0) {
                vis[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(i);
            vis[i - 'a'] = true;
            freq[i - 'a']--;
        }

        string ans = "";
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};