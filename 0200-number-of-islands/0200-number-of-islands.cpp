class Solution {
public:
    bool isvalid(int i,int j,vector<vector<char>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        if(i>=0&&i<m&&j>=0&&j<n&&grid[i][j]=='1')return true;
        return false;
    }
    void dfs(int i,int j,vector<vector<char>>& grid){
        grid[i][j]='0';
        if(isvalid(i+1,j,grid))
            dfs(i+1,j,grid);
        if(isvalid(i-1,j,grid))
            dfs(i-1,j,grid);
        if(isvalid(i,j+1,grid))
            dfs(i,j+1,grid);
        if(isvalid(i,j-1,grid))
            dfs(i,j-1,grid);
    }
    int numIslands(vector<vector<char>>& grid) {

       int ans=0;
       for(int i=0;i<grid.size();i++){
           for(int j=0;j<grid[0].size();j++){
               if(grid[i][j]=='1'){
                   ans++;
                   dfs(i,j,grid);
               }
           }
       } 
       return ans;
    }

    
};