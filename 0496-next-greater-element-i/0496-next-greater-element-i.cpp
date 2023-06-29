class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        int n=nums2.size();
        for(int i=0;i<n;i++){
            mp[nums2[i]]=i;
        }

        vector<int>ans;
        for(int i=0;i<nums1.size();i++){
            
            int res=-1;
            for(int j=mp[nums1[i]];j<n;j++){
                if(nums2[j]>nums1[i]){
                    res=nums2[j];
                    break;
                }
            }
            ans.push_back(res);
        }
        return ans;
    }
};