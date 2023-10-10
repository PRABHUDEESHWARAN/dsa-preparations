#include <bits/stdc++.h>
 
using namespace std;
void check(int startR,int startC,int tRow,int tCol,int r,int c,vector<vector<int>> &arr)
{
    
    
    queue<pair<int,int>> q;
    vector<vector<int>> vis(r,vector<int>(c,0));
    q.push({startR,startC});
    vis[startR][startC]=1;
    //get neighbours
    while(!q.empty())
    {
        pair<int,int> temp=q.front();
        q.pop();
        int currR=temp.first;
        int currC=temp.second;
        if(currR==tRow && currC==tCol)
        {
            cout<<"yes";
            return; 
        }
        int delR[]={-1,0,1,0};
        int delC[]={0,1,0,-1};
        
        
        for(int i=0;i<4;i++)
        {
            int nRow=currR+delR[i];
            int nCol=currC+delC[i];
            
            if(nRow>=0 && nRow<r && nCol>=0 && nCol<c && arr[nRow][nCol]==1)
            {
                if(!vis[nRow][nCol])
                {
                    q.push({nRow,nCol});
                    vis[nRow][nCol]=1;
                }
            }
        }
        
        
    }
    cout<<"no";
    return;
    
}
int main(int argc, char** argv)
{
int r,c;
cin>>r>>c;
vector<vector<int>> arr(r,vector<int>(c));
for(int i=0;i<r;i++)
{
    for(int j=0;j<c;j++)
    {
        cin>>arr[i][j];
    }
}
int startR,startC,tRow,tCol;
cin>>startR>>startC>>tRow>>tCol;
check(startR,startC,tRow,tCol,r,c,arr);

}