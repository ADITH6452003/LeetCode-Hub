    class Solution {
        void solve(vector<int>& nums,int idx,vector<int>& output,vector<vector<int>>& finaloutput){
            if(idx == nums.size()){
                finaloutput.push_back(output);
                return;
            }

            output.push_back(nums[idx]);
            solve(nums,idx+1,output,finaloutput);
            output.pop_back();
            int nextidx = idx+1;
            while(nextidx<nums.size() && nums[nextidx] == nums[idx]){
                nextidx++;
            }
            solve(nums,nextidx,output,finaloutput);
    }
    public:
        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            sort(nums.begin(),nums.end());
            vector<vector<int>>finaloutput;
            vector<int>output;

            solve(nums,0,output,finaloutput);
            return finaloutput;

        }
    };