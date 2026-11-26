class Solution {
public:
void backtrack(vector<int>&nums,int idx,vector<int>&curr,vector<vector<int>>&ans){
    ans.push_back(curr);
    for(int i=idx;i<nums.size();i++){
        if(i>idx && nums[i] == nums[i-1]){
            continue;
        }
        curr.push_back(nums[i]);
        backtrack(nums,i+1,curr,ans);
        curr.pop_back();
    }
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>current;
        sort(nums.begin(),nums.end());
        backtrack(nums,0,current,ans);
        return ans;
    }
};