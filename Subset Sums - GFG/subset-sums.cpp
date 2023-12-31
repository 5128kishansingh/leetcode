//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void  f(vector<int>arr,vector<int>&ans,int i,int sum){
        
        if(i<0)return ans.push_back(sum);
        f(arr,ans,i-1,sum+arr[i]);
        f(arr,ans,i-1,sum);
        
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int>ans;
       f(arr,ans,N-1,0);
       return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends