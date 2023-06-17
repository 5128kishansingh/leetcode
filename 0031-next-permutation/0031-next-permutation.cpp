
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int s=-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1])
               { s=i;break;}
        }
        cout<<s;
        if(s==-1){sort(nums.begin(),nums.end());return;}
        int sw=-1;
        int small=1000;
        for(int i=s+1;i<n;i++){
            if(nums[i]<small && nums[i]>nums[s]){
                small =nums[i];
                sw=i;
            }
        }
        swap(nums[s],nums[sw]);
        sort(nums.begin()+s+1,nums.end());
    }
};