#include<bits/stdc++.h>
using namespace std;
int main()
{
string pat,str;
cin>>pat>>str;
int l2=pat.length()+1,l1=str.length()+1;
int v[l1][l2];
// cout<<v.size();
v[0][0]=1;
for(int i=1;i<l1;i++)
{
    v[i][0]=0;
}
for(int i=1;i<l2;i++)
{
    if(pat[i-1]=='*')
    {
        v[0][i]=v[0][i-1];
    }
    else{
        v[0][i]=0;
    }
}

for(int i=1;i<l1;i++)
{
    for(int j=1;j<l2;j++)
    {
        if(str[i-1]==pat[j-1] || pat[j-1]=='?')
        {
            v[i][j]=v[i-1][j-1];
        }
        else if(pat[j-1]=='*')
        {
            v[i][j]=v[i-1][j]||v[i][j-1];
        }
        else{
            v[i][j]=0;
        }
    }
}



for(int i=0;i<l1;i++)
{
    for(int j=0;j<l2;j++)
    {
        cout<<v[i][j]<<" ";
    }
    cout<<endl;
}


if(v[l1-1][l2-1]==1)
{
    cout<<"yes";
}else cout<<"no";

return 0;
}