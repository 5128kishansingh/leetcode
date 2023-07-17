//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isPalindrome(string str, int start, int end) {
    while (start < end) {
        if (str[start] != str[end])
            return false;
        start++;
        end--;
    }
    return true;
}
    int f(string str,int start,int end,vector<vector<int>> &dp){
        
        if (start >= end || isPalindrome(str, start, end))
        return 0;
        
        if(dp[start][end]!=-1)return dp[start][end];
        int minCuts=INT_MAX;
        for(int i=start;i<end;i++){
            if (isPalindrome(str, start, i)) {
            int cuts = 1 + f(str, i + 1, end, dp);
            minCuts = min(minCuts, cuts);
        }
        }
            return dp[start][end]=minCuts;
    }
    
    int palindromicPartition(string str)
    {
        int n = str.length();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return f(str, 0, n - 1, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends