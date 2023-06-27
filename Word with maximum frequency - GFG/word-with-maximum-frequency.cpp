//{ Driver Code Starts
#include <iostream>
#include <map>
#include <algorithm>
#include <sstream>
using namespace std;



string maximumFrequency(string s);

int main()
{
    int t;cin>>t;
    cin.ignore();

    for(int i=0;i<t;i++)
    {

        string s;
        getline(cin,s);
  

// } Driver Code Ends
      
        
        cout << maximumFrequency(s) << endl;

    }
    return 0;
}
#include<vector>
string maximumFrequency(string s){
        map<string,int>mp;
        vector<string>v;
        string x="";
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                mp[x]++;
                v.push_back(x);
                x="";
            }
            else x+=s[i];
        }
        mp[x]++;
        // cout<<mp[x];
        string maxstr;
        int maxfreq=-1;
        for(int i=0;i<v.size();i++){
            if(mp[v[i]]>maxfreq){
                maxfreq=mp[v[i]];
                maxstr=v[i];
            }
        }
        maxstr+=" ";
        maxstr+=to_string(maxfreq);
        return maxstr;
}

