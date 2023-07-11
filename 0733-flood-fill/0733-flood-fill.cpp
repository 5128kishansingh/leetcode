class Solution {
public:
    bool isvalid(int sr,int sc,vector<vector<int>>& image,int a)
    {   int m=image.size();
        int n=image[0].size();
         if(sr>=0&&sr<m&&sc>=0&&sc<n&&image[sr][sc]==a)
        return true;
         else return false;
    }
    void colorfill(int sr,int sc,vector<vector<int>>& image,int color,int a){
        image[sr][sc]=color;
        if(isvalid(sr+1,sc,image,a))
        colorfill(sr+1,sc,image,color,a);
        if(isvalid(sr-1,sc,image,a))
        colorfill(sr-1,sc,image,color,a);
        if(isvalid(sr,sc+1,image,a))
        colorfill(sr,sc+1,image,color,a);
        if(isvalid(sr,sc-1,image,a))
        colorfill(sr,sc-1,image,color,a);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
      int a=image[sr][sc];
      if(a==color)return image;
      colorfill(sr,sc, image,color,a);
      return image;  
    }
};