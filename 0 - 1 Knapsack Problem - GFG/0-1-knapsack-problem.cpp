//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int f(int i,int weight,int wt[],int val[],vector<vector<int>>&dp){
        if(i<0)return 0;
        if(dp[i][weight]!=-1)return dp[i][weight];
        int nottake=f(i-1,weight,wt,val,dp);
        int take=INT_MIN;
        if(weight>=wt[i])take=val[i]+f(i-1,weight-wt[i],wt,val,dp);
        return dp[i][weight]=max(take,nottake);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    {       
        vector<vector<int>>dp(n,vector<int>(W+1,-1));
         return f(n-1,W,wt,val,dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends