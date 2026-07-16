class Solution {
public:
    vector<char> build(string s) {
        vector<char> v;
        for (char ch : s) {
            if (ch != '#') {
                v.push_back(ch);
            } else if (!v.empty()) {
                v.pop_back();
            }
        }
        return v;
    }
    bool backspaceCompare(string s, string t) {
        vector<char> v1 = build(s);
        vector<char> v2 = build(t);

        return v1 == v2;
    }
};