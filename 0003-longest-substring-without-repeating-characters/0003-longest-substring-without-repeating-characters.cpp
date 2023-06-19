class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_map<int,int>map;
        int i=0;
        int maxi=0;
        while(i<n)
        {
            if(map.find(s[i])==map.end()){
                map[s[i]]=i;
                i++;
                if(map.size()>maxi)maxi=map.size();
            }
            else {
                if(map.size()>maxi)maxi=map.size();
                i=map[s[i]]+1;
                map.clear();
            }

        }
        return maxi;
    }
};