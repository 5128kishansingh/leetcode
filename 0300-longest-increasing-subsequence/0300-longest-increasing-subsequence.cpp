class Solution {
public:
    int f(int i,vector<int>&nums,int flag,
     vector<vector<int>>&dp){
        if(i<0)return 0;

        if(dp[i][flag]!=-1)return dp[i][flag];
        int nottake=f(i-1,nums,flag,dp);
        int take=INT_MIN;
        if(flag==nums.size()||nums[i]<nums[flag])
        take=1+f(i-1,nums,i,dp);

        return dp[i][flag]= max(take,nottake);

    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
       
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return f(n-1,nums,n,dp);
    }
};