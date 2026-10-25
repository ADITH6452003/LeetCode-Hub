class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;++i){
            unordered_map<int,int>freq;
            vector<int> order;
            for(int j = i;j<n;++j){
                int val = nums[j];
                if(freq[val]==0){
                    order.push_back(val);
                }
                freq[val]++;
                int k = order.size();
                long long expected_len = (long long)k*(k+1)/2;
                long long current_len = j-i+1;
                if(current_len == expected_len){
                    bool valid = true;
                    for(int idx = 0;idx<k;++idx){
                        if(freq[order[idx]]!=idx+1){
                            valid = false;
                            break;
                        }
                    }
                    if(valid){
                        ans++;
                    }
                }else if(current_len>expected_len){
                    break;
                }
            }
        }
        return ans;
    }
};