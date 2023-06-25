class Solution {
public:
   void f(vector<int>&nums,set<vector<int>>&
   ans,int i, vector<int>p){
   
    
        if(i<0){sort(p.begin(),p.end()); ans.insert(p);return ;}
       f(nums,ans,i-1,p);
       p.push_back(nums[i]);
       f(nums,ans,i-1,p);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
       set<vector<int>>ans;
        vector<int>p;
        f(nums,ans,n-1,p);
        vector<vector<int>>res(ans.begin(),ans.end());
        return res;
    }
};