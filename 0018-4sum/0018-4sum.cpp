class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        int n=nums.size();
        if(n<4)return ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i>0&&nums[i]==nums[i-1])continue;
            for(int j=i+1;j<n;j++){
                if(j>i+1&&nums[j]==nums[j-1])continue;
                int k=j+1;
                int l=n-1;
                long sum;
                sum=(target-nums[i]);
                sum=sum-nums[j];
                while(k<l){
                    if(nums[k]+nums[l]==sum)
                    {
                        vector<int>temp={nums[i],nums[j],
                        nums[k],nums[l]};
                        ans.push_back(temp);
                        while (k < l && nums[k] == nums[k+1]) k++;
                        while (k < l && nums[l] == nums[l-1]) l--;
                        
                        k++; l--;
                    }
                    else if (nums[k] + nums[l] < sum) k++;
                    else l--;
                }
                // while(nums[j]==nums[j-1])j++;
            }
        }
        return ans;
    }
};