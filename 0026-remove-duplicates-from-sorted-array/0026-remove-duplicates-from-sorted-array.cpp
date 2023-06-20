class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      int n=size(nums),res=1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=nums[res-1])
            {
                nums[res]=nums[i];
                res++;
            }
        }return res;
          
    }
};