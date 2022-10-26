class Solution {
public:
    void getResult(vector<vector<int>> &res,vector<int> &nums,int ind){
        if(ind == nums.size()){
            res.push_back(nums);
            return;
        }    
        for(int i=ind; i<nums.size(); i++){
            swap(nums[i],nums[ind]);
            getResult(res,nums,ind+1);
            swap(nums[i],nums[ind]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        getResult(res,nums,0);
        return res;
    }
};