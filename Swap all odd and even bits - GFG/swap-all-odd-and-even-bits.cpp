//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to swap odd and even bits.
    unsigned int swapBits(unsigned int n){
        for(int i=0; i<32; i+=2){
            
            int i_bit = (n >> i) & 1;
            int i_1_bit = (n >> (i+1)) & 1;
            
            n = n - (i_bit << i) - (i_1_bit << (i+1))
                  + (i_bit << (i+1)) + (i_1_bit << i);
        }
        return n;
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;//testcases
	while(t--)
	{
		unsigned int n;
		cin>>n;//input n
		
		Solution ob;
		//calling swapBits() method
		cout << ob.swapBits(n) << endl;
	}
	return 0;
}
// } Driver Code Ends