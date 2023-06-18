class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      int n=nums.size();
      if(n==0)return 0;
      unordered_set<int>s;
      for(int i=0;i<n;i++)
          s.insert(nums[i]);
    int maxlen=INT_MIN;
       for (const auto& i : s){
          int curr=0;
          if(s.find(i-1)==s.end()){
              curr=1;
              int x=i;
              while(s.find(x+1)!=s.end()){
                  curr++;
                  x=x+1;
              }
                maxlen=max(maxlen,curr);
          }
      }
        return maxlen;
    }
};