class Solution {
public:
    void func(int ind,vector<int> &nums,vector<vector<int>> &ans,vector<int> &ds){
        if(ind == nums.size()){
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[ind]);
        func(ind+1,nums,ans,ds);
        ds.pop_back();
        func(ind+1,nums,ans,ds);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> ans;
        func(0,nums,ans,ds);
        return ans;
    }
};