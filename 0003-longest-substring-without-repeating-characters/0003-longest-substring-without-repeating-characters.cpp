class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left=0,right =0;
        int maxlen =0;
        vector<bool>visited(256,false);
        while(right<n){
            char char_at_right = s[right];
            while(visited[char_at_right]==true){
                visited[s[left]]  = false;
                left++;
            }
            visited[char_at_right] = true;
            maxlen = max(maxlen,right - left+1);
            right++;
        }
        return maxlen;
    }
};