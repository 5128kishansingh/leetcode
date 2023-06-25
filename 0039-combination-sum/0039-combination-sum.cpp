class Solution {
public:
    void f(vector<int>&candidates,int i,vector<int>p,
    vector<vector<int>>&ans,int target){
        if(i<0&&target!=0)return ;
        if(target==0){ans.push_back(p);return ;}

        f(candidates,i-1,p,ans,target);
        if(candidates[i]<=target)
       { p.push_back(candidates[i]);
        f(candidates,i,p,ans,target-candidates[i]);}
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>p;
       int n=candidates.size();
       f(candidates,n-1,p,ans,target); 
       return ans;
    }
};