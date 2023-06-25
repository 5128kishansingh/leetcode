class Solution {
public:
    void f(int ind ,vector<int>&nums,
    vector<vector<int>>&ans){
        if(ind==nums.size()){
            vector<int>v;
            for(int j=0;j<nums.size();j++){
               v.push_back(nums[j]); 
            }
            ans.push_back(v);
            return ;
        }


        for(int i=ind;i<nums.size();i++){
            swap(nums[ind],nums[i]);
            f(ind+1,nums,ans);
            swap(nums[ind],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n= nums.size();
        vector<vector<int>>ans;
        f(0,nums,ans);
        return ans;
    }
};