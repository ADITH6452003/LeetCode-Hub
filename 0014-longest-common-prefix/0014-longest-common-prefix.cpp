class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        sort(strs.begin(), strs.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });

        int minLen = strs[0].size();
        string com = "";

        for (int i = 0; i < minLen; i++) {
            char ch = strs[0][i];
            for (int j = 1; j < static_cast<int>(strs.size()); j++) {
                if (strs[j][i] != ch) {
                    return com;
                }
            }
            com += ch;
        }

        return com;
    }
};