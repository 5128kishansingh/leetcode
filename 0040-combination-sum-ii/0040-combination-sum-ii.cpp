class Solution {
public:
void f(vector<int>&candidates,int ind,vector<int>p,
    vector<vector<int>>&ans,int target){
         if (target == 0) {
    ans.push_back(p);
    return;
  }

        for (int i = ind; i < candidates.size(); i++) {
    if (i > ind && candidates[i] == candidates[i - 1]) continue;
    if (candidates[i] > target) break;
    p.push_back(candidates[i]);
    f(candidates,i+1, p, ans,
    target-candidates[i]);
    p.pop_back();
  }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        // int sum=0;
        // for(auto it:candidates)
        // sum+=it;
        // if(sum<target)return ans;
        vector<int>p;
        
       int n=candidates.size();
       f(candidates,0,p,ans,target); 
       
       return ans;
    }
};