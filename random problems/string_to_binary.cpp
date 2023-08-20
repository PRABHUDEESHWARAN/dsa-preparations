#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int len=s.length(),t=0,res=0;
    for(int i=len-1;i>=0;i--)
    {
        if(s[i]=='a')
        {
            res+=1*pow(2,t++);
        }
        else{
            res+=0*pow(2,t++);
        }
    }
    cout<<res;
    return 0;
}