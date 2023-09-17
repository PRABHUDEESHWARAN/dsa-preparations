#include<bits/stdc++.h>
using namespace std;
/*
Surrounding regions: (bfs)
    -> Given a matrix with zeros and ones we need to replace all the zeros in the matrix with ones if the zeros as a group 
    or individual are surrounding by 1s in all four directions (does not include the diagonals).
    
    Intuition:
        -> We can observe that if a particular zero or a group of zeros are connected to any of the zeros that are present 
        in the boundary then definitely they cant be replaced by 1 or x.
        -> Therefore what we do is, we make a dfs from every node in the boundary that is a zero and mark every zeros
        visited during dfs as visited.
        -> after this process we traverse the given matrix once again and we will convert all the zeros that are not visited
        to 1 or x.
        thats it!!!.
*/

class Solution
{
    public:

        void dfs(int row,int col,vector<vector<char>> &mat,int r,int c,vector<vector<int>> &visited)
        {
            //base condition
            //here we dont need base condition because the for loop are run for a definite time.

            //make the rcurrent location 'O' as visited.
            visited[row][col]=1;
            //check for four directios and call dfs.
            
            int delx[]={-1,0,1,0};
            int dely[]={0,1,0,-1};
            for(int i=0;i<4;i++)
            {
                int nrow=row+delx[i];
                int ncol=col+dely[i];
                if(nrow>=0 && nrow<r && ncol>=0 && ncol<c && mat[nrow][ncol]=='O')
                {
                    if(visited[nrow][ncol]==0)dfs(nrow,ncol,mat,r,c,visited);
                }
            }
        }
        vector<vector<char>> fill(int r,int c,vector<vector<char>> &mat)
        {
            // vector<vector<char>> ans;
            //create visited array.
            vector<vector<int>> visited(r,vector<int>(c,0));
            //do dfs for zeros that are in the boundary.
            
            // for first row.
            for(int i=0;i<c;i++)
            {
                if(mat[0][i]=='O')
                {
                    dfs(0,i,mat,r,c,visited);
                }
            }
            //for last row.
            for(int i=0;i<c;i++)
            {
                if(mat[r-1][i]=='O')
                {
                    dfs(r-1,i,mat,r,c,visited);
                }
            }
            // for first column.
            for(int i=0;i<r;i++)
            {
                if(mat[i][0]=='O')
                {
                    dfs(i,0,mat,r,c,visited);
                }
            }
            // for last column.
            for(int i=0;i<r;i++)
            {
                if(mat[i][c-1]=='O')
                {
                    dfs(i,c-1,mat,r,c,visited);
                }
            }

            //replace zeros with x by checking with visited array.
            for(int i=0;i<r;i++)
            {
                for(int j=0;j<c;j++)
                {
                    if( mat[i][j]=='O' && visited[i][j]==0)
                    {
                        mat[i][j]='X';
                    }
                }
            }
            return mat;
        }
};


int main(){
    
    vector<vector<char>> mat{
        {'X', 'X', 'X', 'X'}, 
        {'X', 'O', 'X', 'X'}, 
        {'X', 'O', 'O', 'X'}, 
        {'X', 'O', 'X', 'X'}, 
        {'X', 'X', 'O', 'O'}
    };
    
    Solution ob;
    // n = 5, m = 4
    vector<vector<char>> ans = ob.fill(5, 4, mat);
    for(int i = 0;i < 5;i++) {
        for(int j = 0;j < 4;j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}