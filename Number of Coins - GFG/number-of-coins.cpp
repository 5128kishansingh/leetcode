//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int f(int coins[],int i,int V,vector<vector<int>>&dp){
	   
	    if(i==0){
	       
	         if(V%coins[0]==0)return V/coins[0];
	        else return 1e9;
	    }
	    if(dp[i][V]!=-1)return dp[i][V];
	    int nottake=f(coins,i-1,V,dp);
	    int take=INT_MAX;
	    if(coins[i]<=V)take=1+f(coins,i,V-coins[i],dp);
	    return dp[i][V]= min(take,nottake);
	}
	int minCoins(int coins[], int M, int V) 
	{ 
	    vector<vector<int>>dp(M,vector<int>(V+1,-1));
	    
	   int ans=f(coins,M-1,V,dp);
	   if(ans==1e9)return -1;
	   else return ans;
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends