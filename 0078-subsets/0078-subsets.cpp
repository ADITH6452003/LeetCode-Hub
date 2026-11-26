class Solution {
public:
void backtrack(vector<int>&nums,int idx,vector<int>&current,vector<vector<int>>&ans){
    if(idx == nums.size()){
        ans.push_back(current);
        return;
    }
    current.push_back(nums[idx]);
    backtrack(nums,idx+1,current,ans);
    current.pop_back();
    backtrack(nums,idx+1,current,ans);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>current;
        vector<vector<int>>ans;
        backtrack(nums,0,current,ans);
        return ans;
    }
};