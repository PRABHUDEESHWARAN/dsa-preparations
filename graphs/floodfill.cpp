#include<bits/stdc++.h>
using namespace std;
/*
Flood Fill : We will be given a matrix representation of an image,
                    -> image with pixel numbers.
                    -> starting pixel.
                    -> color to fill (flood)
            -> Our task is to fill the matrix with the given color with the following conditions    
                    -> for a given pixel color only the four directions of that pixel
                        ->top,down,left,right.
                    -> You can color a pixel with the given color only if the current color of the pixel is
                        equal to the initial color of the starting pixel provided as input.
        INTUITION:
            -> we can solve this problem by using dfs or bfs.let us see the dfs approach.
            -> at each node we fill the four neighbours with the color intended given the cell meets the conditions.
*/

class Solution
{
    private:
        void dfs(int row,int col,vector<vector<int>> &image,vector<vector<int>>&ans,int initColor,int color)
        {
            int n=image.size();
            int m=image[0].size();
            if(row>=n || row<0 || col>=m || col<0 || ans[row][col]!=initColor)
            {
                return;
            }
            ans[row][col]=color;
            int drow[]={-1,0,1,0};
            int dcol[]={0,1,0,-1};
            for(int i=0;i<4;i++)
            {
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                // if(nrow>0 && nrow<n && ncol>0 && ncol<m && ans[nrow][ncol]==initColor)
                // {

                // }
                dfs(nrow,ncol,image,ans,initColor,color);
            }

        }
    public:
        vector<vector<int>> floodFill(vector<vector<int>> &image,int sr,int sc,int color)
        {
            int initColor=image[sr][sc];
            if(color == initColor) return image;
            vector<vector<int>> ans=image;
            dfs(sr,sc,image,ans,initColor,color);

            return ans;
        }
};

int main(){
		
	vector<vector<int>>image{
	    {1,1,1},
	    {1,1,0},
	    {1,0,1}
	};
	
// sr = 1, sc = 1, newColor = 2  	
	Solution obj;
	vector<vector<int>> ans = obj.floodFill(image, 1, 1, 2);
	for(auto i: ans){
		for(auto j: i)
			cout << j << " ";
		cout << "\n";
	}
	
	return 0;
}