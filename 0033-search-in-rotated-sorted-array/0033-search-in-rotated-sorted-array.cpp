class Solution {
public:
   
    int search(vector<int>& nums, int target) {
       int n=nums.size();
       int k;
       for(int i=1;i<n;i++){
           if(nums[i]<nums[i-1])
           {k=i;break;}
       } 
       int it=lower_bound(nums.begin(),nums.begin()+k,
       target)-nums.begin();
       if(it<n&&nums[it]==target)return it;
      int  t=lower_bound(nums.begin()+k,nums.end(),
       target)-nums.begin();
       if(t<n&&nums[t]==target)return t;
       return -1;
    }
};