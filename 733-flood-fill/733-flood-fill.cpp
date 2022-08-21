class Solution {
public:
void helper(vector<vector<int>>& image, int i, int j, int color,int startColor, int n, int m,vector<vector<int>>& vis){
        //if i and j are in grid only
        if(i<0 || j<0 || i>=n || j>=m){
            return;
        }
        //if already visited or not desied color
        if(vis[i][j] || image[i][j]!=startColor){
            return;
        }
        //mark this color and move all possible 4 directions
        vis[i][j]=1;
        image[i][j]=color;
        helper(image,i+1,j,color,startColor,n,m,vis);
        helper(image,i,j+1,color,startColor,n,m,vis);
        helper(image,i-1,j,color,startColor,n,m,vis);
        helper(image,i,j-1,color,startColor,n,m,vis);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size(); 
        int m=image[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        //start color
        int startColor=image[sr][sc];
        //color all cells in one dfs only from starting coordinates
        helper(image,sr,sc,color,startColor,n,m,vis);
        return image;
    }
};
