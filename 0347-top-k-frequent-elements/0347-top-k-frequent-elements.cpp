class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        for(auto x:nums){
            m[x]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        for(auto x:m){
            q.push(make_pair(x.second,x.first));
            if(q.size()>k)
            q.pop();
        }
        vector<int>v;
        while(!q.empty())
        {
            pair<int,int> temp=q.top();
            q.pop();
            v.push_back(temp.second);
        }
        return v;
    }
};