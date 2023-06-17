class Solution {
public:
    static bool sortcol( vector<int>& v1, vector<int>& v2)
       {
          return v1[0] < v2[0];
       }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       
       sort(intervals.begin(),intervals.end(), sortcol);

        vector<int>temp;
        vector<vector<int>>ans;
        temp=intervals[0];
        int n=intervals.size();
        for(int i=1;i<n;i++){
            if(intervals[i][0]<=temp[1]){
                temp[1]=max(intervals[i][1],temp[1]);
            }
            else{
                ans.push_back(temp);
                temp[0]=intervals[i][0];
                temp[1]=intervals[i][1];
            }
        }
       ans.push_back(temp);
        return ans;
    }
};