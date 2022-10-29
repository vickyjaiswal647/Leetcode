class Solution {
public:
    void findCombination(int ind,int tar,vector<int> &candidates,vector<int> &arr,vector<vector<int>> &ans){
        if(tar == 0){
            ans.push_back(arr);
            return;
        }
        for(int i=ind; i<candidates.size(); i++){
            if((i>ind) && (candidates[i]==candidates[i-1]))continue;
            if(candidates[i] > tar)break;
            
            arr.push_back(candidates[i]);
            findCombination(i+1,tar-candidates[i],candidates,arr,ans);
            arr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> arr;
        sort(candidates.begin(),candidates.end());
        findCombination(0,target,candidates,arr,ans);
        return ans;
    }
};