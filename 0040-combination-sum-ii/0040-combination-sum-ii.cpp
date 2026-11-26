class Solution {
public:
void backtrack(vector<int>& nums,int idx,int target,vector<int>&curr,vector<vector<int>>&ans,int currsum = 0){
    if(currsum == target){
        ans.push_back(curr);
        return;
    }
    for(int i=idx;i<nums.size();i++){
        if(i>idx && nums[i] == nums[i-1]){
            continue;
        }
        curr.push_back(nums[i]);
        int next = currsum+nums[i];
        if(next>target){
            curr.pop_back();
            break;
        }
        backtrack(nums,i+1,target,curr,ans,currsum+nums[i]);
        curr.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<int>curr;
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        backtrack(nums,0,target,curr,ans);
        return ans;
    }
};