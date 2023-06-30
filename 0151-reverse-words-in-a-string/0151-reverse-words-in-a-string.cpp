class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        string temp="";
        vector<string>v;
        for(int i=0;i<n;i++){
            if(s[i]==' '&&temp.size()==0)continue;
            else if(s[i]!=' ')temp=temp+s[i];
             else if(s[i]==' '&&temp.size()!=0){
                 v.push_back(temp);
                 temp="";
             }
        } 
        if(temp.size()>0)
        v.push_back(temp);
        string ans="";
        int m=v.size();
        // ans=ans+v[m-1];
        for(int i=m-1;i>0;i--)
        ans=ans+v[i]+' ';
        ans=ans+v[0];
        return ans;
    }
};