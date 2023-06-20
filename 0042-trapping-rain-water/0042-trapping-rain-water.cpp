class Solution {
public:
    int trap(vector<int>& height) {
       int n=height.size();
       vector<int>rmax;
       vector<int>lmax;
       int maxi=INT_MIN;
       for(int i=0;i<n;i++){
           maxi=max(maxi,height[i]);
           lmax.push_back(maxi);
       }
       maxi=INT_MIN;
       for(int i=n-1;i>=0;i--){
           maxi=max(maxi,height[i]);
           rmax.push_back(maxi);
       }
       reverse(rmax.begin(),rmax.end());
       int sum=0;
       for(int i=0;i<n;i++){
           int l=min(rmax[i],lmax[i])-height[i];
           sum=sum+l;
       }
       return sum;
    }
};