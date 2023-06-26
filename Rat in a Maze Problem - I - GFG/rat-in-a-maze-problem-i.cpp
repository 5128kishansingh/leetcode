//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool isvalid(int i,int j,vector<vector<int>> &m){
        int n=m.size();
        if(i>=0&&i<n&&j>=0&&j<n&&m[i][j]==1)return true;
        return false;
    }
    void f(vector<vector<int>> &m,int i,int j,vector<string>&ans
    ,string s){
        int n=m.size();
        if(i==n-1&&j==n-1){ans.push_back(s);
            return ;
        }
        
        if(isvalid(i+1,j,m)){
            s+='D';
            m[i][j]=-1;
            f(m,i+1,j,ans,s);
            s.pop_back();
            m[i][j]=1;
        }
        if(isvalid(i,j+1,m)){s+='R';
             m[i][j]=-1;
            f(m,i,j+1,ans,s);
            s.pop_back();
            m[i][j]=1;
        }
        if(isvalid(i-1,j,m)){
            s+='U';
            m[i][j]=-1;
            f(m,i-1,j,ans,s);
            s.pop_back();
            m[i][j]=1;
        }
        if(isvalid(i,j-1,m)){
            s+='L';
            m[i][j]=-1;
            f(m,i,j-1,ans,s);
            s.pop_back();
            m[i][j]=1;
        }
         
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
    vector<string>ans;
    string s="";
    if(m[0][0]==0||m[n-1][n-1]==0)return ans;
       f(m,0,0,ans,s);
       return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends