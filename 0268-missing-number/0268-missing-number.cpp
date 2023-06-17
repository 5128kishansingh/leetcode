class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n=nums.size();
        int sum=n*(n+1)/2;
        int res=0;
        for(int it:nums)
            res+=it;
        return sum-res;
    }
};