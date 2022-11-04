//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isValid(int row,int col,vector<vector<int>> &board,int n){
        int duprow = row;
        int dupcol = col;
        while(row >= 0 && col >= 0){
            if(board[row][col] > 0)return false;
            row--;
            col--;
        }
        row = duprow;
        col = dupcol;
        while(col >= 0){
            if(board[row][col] > 0)return false;
            col--;
        }
        col = dupcol;
        while(col >= 0 && row < n){
            if(board[row][col] > 0)return false;
            row++;
            col--;
        }
        return true;
    }
    void solve(int col,vector<vector<int>> &board,vector<vector<int>> &ans,int n,vector<int> &tmp){
        if(col == n){
            
            // for(int i=0; i<n; i++){
            //     for(int j=0; j<n; j++){
            //         if(board[i][j] > 0)tmp.push_back(j+1);
            //     }
            // }
            ans.push_back(tmp);
            return;
        }
        for(int row=0; row<n; row++){
            if(isValid(row,col,board,n)){
                
                board[row][col] = 1;
                tmp.push_back(row+1);
                solve(col+1,board,ans,n,tmp);
                board[row][col] = 0;
                tmp.pop_back();
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> ans;
        vector<vector<int>> board(n,vector<int> (n,0));
        vector<int> tmp;
        solve(0,board,ans,n,tmp);
        //vector<int> temp;
        //temp = ans.pop_back()
        //reverse(ans.begin(),ans.end());
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends