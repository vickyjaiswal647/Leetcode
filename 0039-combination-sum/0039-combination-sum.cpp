class Solution {
    void getResult(int ind,int tar,vector<int> &arr,vector<vector<int>> &v2, vector<int> &v1){
        //if(sum > tar)return;
        if(ind == arr.size()){
            if(tar == 0){
                v2.push_back(v1);
            }
            return;
        }
        //sum += arr[ind];
        
        if(arr[ind] <= tar){
            v1.push_back(arr[ind]);
            getResult(ind,tar-arr[ind],arr,v2,v1);
            v1.pop_back();       
        }    
        //not pick
        //sum -= arr[ind];
     
        getResult(ind+1,tar,arr,v2,v1);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //int n = candidates.size();
        vector<int> v1;
        vector<vector<int>> v2;
        getResult(0,target,candidates,v2,v1);
        return v2;
    }
};