class Solution {
public:
    int f(int i,int j,string &word1,string &word2,
     vector<vector<int>>&dp){
        if(j<0&&i<0)return 0;
       else if(i<0&&j>=0)return j+1;
        else if(j<0&&i>=0)return i+1;

        if(dp[i][j]!=-1)return dp[i][j];

        if(i>=0&&j>=0){
        if(word1[i]==word2[j])
             return dp[i][j]= f(i-1,j-1,word1,word2,dp);
        else{
            int insert=1+f(i,j-1,word1,word2,dp);
            int delet=1+f(i-1,j,word1,word2,dp);
            int replace=1+f(i-1,j-1,word1,word2,dp);
        return dp[i][j]= min(insert,min(delet,replace));
        }}
        return 0;
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,word1,word2,dp);
    }
};