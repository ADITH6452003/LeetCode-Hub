class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long>gains;
        long long current_sum = 0;
        for(int x:nums){
            current_sum+=x;
            string s = to_string(x);
            sort(s.rbegin(),s.rend());
            long long max_val = stoll(s);
            gains.push_back(max_val-x);
        }
        sort(gains.rbegin(),gains.rend());
        for(int i=0;i<k && i<n;++i){
            if(gains[i]>0){
                current_sum+=gains[i];
            }
        }
        return current_sum;
    }
};