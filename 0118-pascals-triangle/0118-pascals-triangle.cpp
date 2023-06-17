class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // vector<vector<int>>ans;
        // vector<int>v;
        // v.push_back(1);
        // ans.push_back(v);
        // if(numRows==1)return ans;
        // for(int i=1;i<numRows;i++){
        //     vector<int>a;
        //     a.push_back(1);
        //     for(int j=1;j<v.size();j++){
        //         int m=v[j-1]+v[j];
        //         a.push_back(m);
        //     }
        //     a.push_back(1);
        //     ans.push_back(a);
        //     v=a;
        // }
        // return ans;
         vector<vector<int>> output(numRows);
        for(int i=0; i<numRows; i++){
            output[i].resize(i+1, 1);
            for(int j=1; j<i; j++){
                output[i][j] = output[i-1][j-1] + output[i-1][j];
            }
        }
        return output;
    }
};