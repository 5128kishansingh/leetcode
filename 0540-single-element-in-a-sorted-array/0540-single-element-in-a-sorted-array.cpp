class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        if(nums[0]!=nums[1]&&nums[1]==nums[2])
        return nums[0];
        
        int l=0;
        int h=n-1;
        while(l<=h){
            int mid=l+(h-l)/2;

            if(nums[mid-1]!=nums[mid]&&nums[mid+1]
            !=nums[mid])return nums[mid];

            else if(mid%2==0){
                if(nums[mid]==nums[mid+1])l=mid+1;
                else if(nums[mid-1]==nums[mid])
                h=mid-1;
            }
            else if(mid%2!=0){
                if(nums[mid-1]==nums[mid])l=mid+1;
                else if(nums[mid]==nums[mid+1])h=mid-1;
            }
        }
        return 0;
    }
};