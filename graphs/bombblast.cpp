#include<bits/stdc++.h>
using namespace std;

class Pair {
    public:
        int x,y;
        int rad;
        Pair(int a,int b,int r) {
            x=a;
            y=b;
            rad=r;
        }
};

bool isValid(int i,int j,int n,vector<vector<bool>>& visited) {
    return i>=0 && i<n && j>=0 && j<n && !visited[i][j];
}

int bfs(int n,vector<string>& mat) {
    queue<Pair*> q;
    vector<vector<bool>> visited(n,vector<bool>(n,false));
    int peopleCnt=0;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (isdigit(mat[i][j])) {
                q.push(new Pair(i,j,mat[i][j]-'0'));
                visited[i][j]=true;
            } else if(mat[i][j]=='P') {
                peopleCnt++;
            }
        }
    }
    int delx[]={-1,-1,-1,0,0,1,1,1};
    int dely[]={-1,0,1,-1,1,-1,0,1};
    while (!q.empty()) {
        Pair* p=q.front();
        q.pop();
        if (p->rad==0) {
            continue;
        }
        for (int i=0;i<8;i++) {
            int newx=p->x+delx[i];
            int newy=p->y+dely[i];
            if (isValid(newx,newy,n,visited)) {
                if (mat[newx][newy]=='P') {
                    peopleCnt--;
                }
                Pair* adj=new Pair(newx,newy,p->rad-1);
                q.push(adj);
                visited[newx][newy]=true;
            }
        }
    }
    return peopleCnt;
}

int main()
{
    int n;
    cin>>n;
    vector<string> mat(n);
    for (int i=0;i<n;i++) {
        cin>>mat[i];
    }
    cout<<bfs(n,mat);
    return 0;
}