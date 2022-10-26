class Solution {
public:
    void getResult(vector<vector<int>> &res,vector<int> &arr,vector<bool> &visited,vector<int> &nums){
        if(nums.size() == arr.size()){
            res.push_back(arr);
            return;
        }    
        for(int i=0; i<nums.size(); i++){
            if(!visited[i]){
                arr.push_back(nums[i]);
                visited[i] = true;
                getResult(res,arr,visited,nums);
                visited[i] = false;
                arr.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> arr;
        vector<bool> visited(n,false);
        getResult(res,arr,visited,nums);
        return res;
    }
};