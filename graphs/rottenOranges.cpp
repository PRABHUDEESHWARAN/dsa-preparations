#include<bits/stdc++.h>
using namespace std;
/*
Rotten Oranges: given a matrix consisting of 3 values,
        -> 1 - fresh orange.
        -> 2 - rotten orange.
        -> 0 - empty cell.
    -> our task is to return the total time taken for all the oranges to become rotten.
    NOTE: every rotten orange makes its neighbouring 4 oranges rotten in 1 units of time.
    ->SOLUTION:
        -> since we need to reach 1 level in all direction at every node, we use BFS.

*/
int orangesRotting(vector<vector<int>> &v)
{
    int cnt=0;
    int n=v.size(); //rows
    int m=v[0].size();//cols
    int vis[n][m];//visited matrix.
    queue<pair<pair<int,int>,int>> q; // {{i,j},time}
    //find the pos of rotten oranges and put them in the queue.
    int freshOranges=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(v[i][j]==2)
            {
            q.push({{i,j},0});
            vis[i][j]=1; // visit the rotten oranges that are already present.
            }
            else if(v[i][j]==1)
            {
                freshOranges++;
                vis[i][j]=0;
            }
            else{
                vis[i][j]=0;
            }
            
        }
    }
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    int time=0;
    while(!q.empty())
    {
        int row=q.front().first.first;
        int col=q.front().first.second;
        int t=q.front().second;
        q.pop(); // remove the rotten orange.
        //update max time.
        time=max(time,t);

        //find neighbours.
        for(int i=0;i<4;i++)
        {
            int drow=row+dx[i];
            int dcol=col+dy[i];
            if(drow>=0 && drow<n && dcol>=0 && dcol<m && vis[drow][dcol]==0 && v[drow][dcol]==1) // check if not visited and its fresh.
            {
                vis[drow][dcol]=1; //visit them.
                v[drow][dcol]=2; // make them rotten.
                q.push({{drow,dcol},t+1});
                cnt++;
            }
        }

    }

    if(cnt!=freshOranges)
    {
        return -1;
    }

    return time;
}


int main()
    {
        vector<vector<int>> v{ {2,1,1} , {1,1,0} , {0,1,1} } ;
        int rotting = orangesRotting(v);
        cout<<"Minimum Number of Minutes Required "<<rotting<<endl;
        
    }