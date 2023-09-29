//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/*
Number of Enclaves: Given a 2d grid with 0's and 1's, The zeros represent sea cell and 1 represent land cell
we need to given the number of land cells in the grid through which we cannot reach the boundary.
NOTE: we can use any number of moves to move from one land cell to another.

Intuition: This problem is very much similar to the flood fill problem, here 
    -> we can do a bfs or dfs from all the land cells(1's) that are present in the boundary
    -> doing a bfs from land cells on the boundary will make sure that all the connected land cells are visited.
    -> after doing the traversal we can either traverse the grid again and count the number of ones that are not visites
    or we can use a variable to have a count of total number of ones that are not present in the boundary decrement them
    during traversal if visited.
*/




// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        
        //answer varible
        int onesCnt=0;
        
        // row and col size
        int n=grid.size(),m=grid[0].size();
        //create a visited array.
        int visited[n][m]={0};
        // need a queue to do bfs;
        queue<pair<int,int>> q;
        // put boundary values that are 1 into queue.
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                // take boundary ones to start multistart bfs
                if(grid[i][j]==1 && (i==0 || i==n-1 || j==0 || j==m-1))
                {
                    //push into queue as well mark them as visited
                    
                    q.push({i,j});
                    visited[i][j]=1;
                }
                else if(grid[i][j]==1)onesCnt++;
            }
        }
        // start traveral
        while(!q.empty())
        {
            pair<int,int>curr=q.front();
            int crow=curr.first;
            int ccol=curr.second;
            q.pop();
            // get the neighbours of the curr node.
            //we have four directions
            
            int delx[]={-1,0,1,0};
            int dely[]={0,1,0,-1};
            
            for(int i=0;i<4;i++)
            {
                //get neighbour
                int nrow=crow+delx[i];
                int ncol=ccol+dely[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m)
                {
                    if(!visited[nrow][ncol] && grid[nrow][ncol]==1)
                    {
                        q.push({nrow,ncol});
                        visited[nrow][ncol]=1;
                        onesCnt--;
                    }
                }
            }
        }
        return onesCnt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends