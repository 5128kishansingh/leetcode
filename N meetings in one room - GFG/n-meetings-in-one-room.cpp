//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    static bool compare(pair<int,int>p1,pair<int,int>p2){
         return   p1.second<p2.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            pair<int,int>p;
            p.first=start[i];
            p.second=end[i];
            v.push_back(p);
        }
        sort(v.begin(),v.end(),compare);
        int sum=0;
        int l=-1;
        // for(int i=0;i<n;i++){
        //     cout<<v[i].second<<" ";
        // }
        for(int i=0;i<n;i++){
            pair<int,int>p=v[i];
            if(p.first>l){
                sum++;
                l=p.second;
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends